#ifndef NodeType_h
#define NodeType_h

template <class elemType>
struct NodeType
{
	elemType info;
	NodeType<elemType> *link;
	NodeType<elemType>() : info(NULL), link(NULL) {}
	NodeType<elemType>(elemType theVal) : info(theVal), link(NULL) {}
};

#endif /* NodeType_h */
