class StartDialog{
    private:
        int map_height;
        int map_width;
        bool is_size_set;
    public:
        //initialization
        StartDialog();

        //map
        int getHeight();
        int getWidth();

        //executor
        void executor();
};
