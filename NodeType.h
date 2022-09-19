#ifndef NodeType_h
#define NodeType_h

template <class elemType>
struct NodeType
{
	elemType info;
	NodeType<elemType> *link;
};

#endif /* NodeType_h */
