#ifndef DLINK_H
#define DLINK_H


class DLink
{
    public:
        DLink(int value = 0, DLink * next = nullptr, DLink * prev = nullptr);

        void setNext(DLink * next);
        void setPrev(DLink * prev);

        int getValue();
        DLink * getNext();
        DLink * getPrev();

    private:
        int value;
        DLink * next;
        DLink * prev;
};

#endif // DLINK_H
