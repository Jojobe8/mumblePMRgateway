#ifndef EXTERNALPTT_H_
    #define EXTERNALPTT_H_

    class ExternalPTT
    {
        public:
            ExternalPTT();
            ~ExternalPTT();

            bool init(void);
            bool getPINsetting(void);
            bool getPTTstate(void);
            bool setSQLstate(bool sqlstate);
            bool getSavePTTstate(void);
        
        private:
        
        protected:
            bool save_bInitialized;
            bool save_bPTTState;
            int SQLpin;
            int PTTpin;
};
#endif // EXTERNALPTT_H_
