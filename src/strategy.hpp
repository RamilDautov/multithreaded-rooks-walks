#if !defined(_STRATEGY_H_)
#define _STRATEGY_H_

class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual void run() = 0;
};

#endif // _STRATEGY_H_