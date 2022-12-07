class Carlo{
    public:
        Carlo(double Weight = 0, double Price = 0);
        virtual ~Carlo();
        void SetCarlo(double = 0, double = 0);
        const double &GetCurrentTotalWeight() const;
        const double &GetCurrentTotalPrice() const;
        void BuyBox();
        void SellBox();
        void ShowBoxInfor() const;

    protected:
        static double TotalWeight;
        static double TotalPrice;

    private:
        double BoxWeight;
        double BoxPrice;
};
