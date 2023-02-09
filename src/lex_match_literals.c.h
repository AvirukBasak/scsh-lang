#ifndef LEX_MATCH_LITERALS_CH
#define LEX_MATCH_LITERALS_CH

LexToken lex_match_char(FILE *f, char ch)
{
    if (ch == '\'') {
        // pop out quote symbol
        lex_buffpop();
        do {
            // can't use lex_getc as it doesn't buffer delimiters
            ch = getc(f);
            if (ch == '\\') {
                lex_buffpush(getc(f));
                continue;
            }
            if (ch == '\'') break;
            if (ch == (char) EOF) lex_throw("unexpected end of file");
            lex_buffpush(ch);
        } while (true);
        return LEXTOK_CHAR_LITERAL;
    }
    return LEXTOK_INVALID;
}

LexToken lex_match_string(FILE *f, char ch)
{
    if (ch == '"') {
        // pop out quote symbol
        lex_buffpop();
        do {
            // can't use lex_getc as it doesn't buffer delimiters
            ch = getc(f);
            if (ch == '\\') {
                lex_buffpush(getc(f));
                continue;
            }
            if (ch == '"') break;
            if (ch == (char) EOF) lex_throw("unexpected end of file");
            lex_buffpush(ch);
        } while (true);
        return LEXTOK_STR_LITERAL;
    }
    return LEXTOK_INVALID;
}

typedef enum {
    LEXBASE_2  =  2,
    LEXBASE_8  =  8,
    LEXBASE_10 = 10,
    LEXBASE_16 = 16,
} LexBase;

bool lex_isbindigit(char c) {
    return c >= '0' && c <= '1';
}

bool lex_isoctdigit(char c) {
    return c >= '0' && c <= '7';
}

bool lex_isdecdigit(char c) {
    return c >= '0' && c <= '9';
}

bool lex_ishexdigit(char c) {
    return (c >= '0' && c <= '9')
        || (c >= 'a' && c <= 'f')
        || (c >= 'A' && c <= 'F');
}

typedef bool (*lex_digitchecker_ft)(char);
lex_digitchecker_ft lex_get_dgitchecker(LexBase base)
{
    switch (base) {
        case LEXBASE_2: return lex_isbindigit;
        case LEXBASE_8: return lex_isoctdigit;
        case LEXBASE_16: return lex_ishexdigit;
        default: return lex_isdecdigit;
    }
}

LexToken lex_match_unum(FILE *f, char ch, LexBase base)
{
    // get digit checker based on base
    lex_digitchecker_ft lex_isdigit = lex_get_dgitchecker(base);
    // get token type based on base
    LexToken inttok, floattok;
    switch (base) {
        case LEXBASE_2:
            inttok = LEXTOK_BININT_LITERAL;
            floattok = LEXTOK_BINFLOAT_LITERAL;
            break;
        case LEXBASE_8:
            inttok = LEXTOK_OCTINT_LITERAL;
            floattok = LEXTOK_OCTFLOAT_LITERAL;
            break;
        case LEXBASE_16:
            inttok = LEXTOK_HEXINT_LITERAL;
            floattok = LEXTOK_HEXFLOAT_LITERAL;
            break;
        default:
            inttok = LEXTOK_DECINT_LITERAL;
            floattok = LEXTOK_DECFLOAT_LITERAL;
            break;
    }
    bool found_point = false;
    bool found_exp = false;
    while (true) {
        ch = lex_getc(f);
        if (ch == '.' && !found_exp) {
            // '.' should be followed by digit
            ch = lex_getc(f);
            if (!lex_isdigit(ch))
                return LEXTOK_INVALID;
            else lex_ungetc(&ch, f);
            if (!found_point) {
                found_point = true;
                continue;
            } else {
                lex_ungetc(&ch, f);
                return floattok;
            }
        // for scientific representation of numbers, 0x0Ap2C implies 0A * (10 ** 2C) in base 16
        // lexes numbers like 12e+34 or 0x0e2p-2d
        } else if ((ch == 'e' && base != LEXBASE_16) || ch == 'p') {
            // 'e' or 'p' should be followed by digit or sign
            ch = lex_getc(f);
            if (ch != '+' && ch != '-' && !lex_isdigit(ch))
                return LEXTOK_INVALID;
            else lex_ungetc(&ch, f);
            if (!found_exp) {
                // replace 'p' with small 'e'
                char *bc = &(lex_get_buffstr()[lex_buffer->push_i -1]);
                if (*bc == 'p') *bc = 'e';
                found_exp = true;
                // consume following sign if present
                ch = lex_getc(f);
                if (ch != '+' && ch != '-') lex_ungetc(&ch, f);
                continue;
            } else {
                lex_ungetc(&ch, f);
                if (found_point) return floattok;
                else return inttok;
            }
        }
        else if (lex_isdigit(ch)) {
            // uppercase all hex digits
            char *bc = &(lex_get_buffstr()[lex_buffer->push_i -1]);
            if (*bc >= 'a' && *bc <= 'f') (*bc) -= ('a' - 'A');
            continue;
        }
        // sometimes _ is used for readability, ignore it
        else if (ch == '_') {
            // ensure _ is followed by valid digits
            ch = lex_getc(f);
            if (!lex_isdigit(ch)) {
                lex_ungetc(&ch, f);      // unget ch
                lex_ungetc(&ch, f);      // unget _
                return found_point ? floattok : inttok;
            } else lex_ungetc(&ch, f);   // unget ch
            lex_buffpop();
        }
        else {
            lex_ungetc(&ch, f);
            if (found_point) return floattok;
            else return inttok;
        }
    }
    return LEXTOK_INVALID;
}

LexToken lex_match_numeric(FILE *f, char ch)
{
    // if starts with a 0
    if (ch == '0') {
        ch = lex_getc(f);
        switch (ch) {
            case 'b': {
                // pop "0b"
                lex_buffpop();
                lex_buffpop();
                return lex_match_unum(f, ch = '0', LEXBASE_2);
            }
            case 'x': {
                // pop "0x"
                lex_buffpop();
                lex_buffpop();
                return lex_match_unum(f, ch = '0', LEXBASE_16);
            }
            default: {
                // for values like 023... and 00.12... and many others
                if (isdigit(ch)) {
                    // pop leading 0
                    lex_ungetc(&ch, f);
                    lex_buffpop();
                    ch = lex_getc(f);
                    return lex_match_unum(f, ch, LEXBASE_8);
                }
                // for numbers like 0.12... or 0_34, or just 0
                else {
                    // unget leading 0
                    lex_ungetc(&ch, f);
                    return lex_match_unum(f, ch, LEXBASE_10);
                }
            }
        }
    }
    // starts with any other number
    else if (isdigit(ch))
        return lex_match_unum(f, ch, LEXBASE_10);
    // starts with '.'
    else if (ch == '.') {
        lex_ungetc(&ch, f);      // unget '.'
        lex_buffpush(ch = '0');  // push a 0
        return lex_match_unum(f, ch, LEXBASE_10);
    }
    else return LEXTOK_INVALID;
}

#endif
