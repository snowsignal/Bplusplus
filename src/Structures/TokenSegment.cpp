#include "../../Include/TokenSegment.h"

TokenSegment::TokenSegment()
{
    std::cout<<"Creating new TokenSegment with currentinc:"<<currentInc<<std::endl;
}

TokenSegment::~TokenSegment()
{
    //dtor
}

void TokenSegment::push_back(Token t)
{
    tokens.push_back(t);
}
void TokenSegment::next() { currentInc++;}
Token TokenSegment::get(){ std::cout<<currentInc<<std::endl; return tokens[currentInc]; }
TokenType TokenSegment::type(){return tokens[currentInc].getType(); }
std::string TokenSegment::value(){return tokens[currentInc].getValue(); }
int TokenSegment::size(){ return tokens.size(); }
Token& TokenSegment::at(int loc) { return tokens.at(loc); }
void TokenSegment::reset() { currentInc = 0; }
void TokenSegment::erase(std::vector<Token>::iterator erasearea)
{
    tokens.erase(erasearea);
}
std::string TokenSegment::getStringValue()
{
    std::string ret;
    for(auto t : tokens)
    {
        ret += t.getValue();
    }
    return ret;
}

        void TokenSegment::append(Token t){ tokens.push_back(t); }
        TokenSegment TokenSegment::createUntil(std::initializer_list<TokenType> tokentypeil,TokenSegment& ts,bool processing_loop)
        {
            TokenSegment ret;
            bool processing = true;
            std::cout<<"Parsing ("<<ts.getStringValue()<<")\n";
            unsigned int current_scope = ts.scope();
            while(processing && !ts.end())
            {
                for(auto tt : tokentypeil)
                {
                    if(ts.type() == tt && (ts.scope() == current_scope || !processing_loop))
                    {
                        processing = false;
                    }
                }
                if(!processing) break;
                ret.push_back(ts.get());
                std::cout<<"Iterating";
                ts.next();
            }
            return ret;
        }