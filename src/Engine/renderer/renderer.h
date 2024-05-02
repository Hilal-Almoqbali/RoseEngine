
namespce rose
{
    class renderer
    {
    public:
        renderer();
        void add_seen(int ID,std::string name, Model model);
        void draw();
        void rm_opject_by_id(int ID);
        void rm_opject_by_name(std::string name);
        void rm_seen();
        ~renderer()=defult;
    private:
    };
}
