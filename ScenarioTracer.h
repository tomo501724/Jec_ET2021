#pragma once

class ScenarioTracer{
    private:
        enum State{
            UNDEFINED,
            INITIAL,
            WALKING
        };
        State mState;
        
        void execUndefined();
        void execInitial();
        void execWalking();

};