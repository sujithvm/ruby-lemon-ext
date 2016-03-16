#include "_lemon_math.h"

// Ruby
#include <ruby.h>

// Lemon
#include <lemon/list_graph.h>

using namespace lemon;


static VALUE rb_cListDigraph;
static VALUE rb_cListDigraphNode;


// ListDigraph::Node

static ListDigraphBase::Node* getListDigraphNode(VALUE self) {
	ListDigraphBase::Node* p;
	Data_Get_Struct(self, ListDigraphBase::Node, p); 
	return p;
}


// ListDigraph

static void wrap_ListDigraph_free(ListDigraph* p) {  
	delete p;
}

static VALUE wrap_ListDigraph_alloc(VALUE self) {
	ListDigraph* ldg = new ListDigraph ;
	return Data_Wrap_Struct(self, NULL, wrap_ListDigraph_free, ldg);
}

static ListDigraph* getListDigraph(VALUE self) {
	ListDigraph* p;	
	Data_Get_Struct(self, ListDigraph, p); 
	return p;
}

static VALUE wrap_ListDigraph_initialize(VALUE self) {
	return self;
}

static VALUE wrap_ListDigraph_clear(VALUE self) {
	getListDigraph(self)->clear();	
	return self;
}

static VALUE wrap_ListDigraph_countNodes(VALUE self) {
	return INT2NUM( countNodes(*getListDigraph(self)) );
}

static VALUE wrap_ListDigraph_addNode(VALUE self) {
	ListDigraphBase::Node node = getListDigraph(self) -> addNode();
	return Data_Wrap_Struct(rb_cListDigraphNode, NULL, NULL, &node);
}

static VALUE wrap_ListDigraph_erase(VALUE self, VALUE node) {
	getListDigraph(self) -> erase(*getListDigraphNode(node));
	return self;
}

void register_list_graph(VALUE rb_mlemon) {
  
	rb_cListDigraph = rb_define_class_under(rb_mlemon, "ListDigraph", rb_cObject);	
	rb_define_alloc_func(rb_cListDigraph, wrap_ListDigraph_alloc);
	rb_define_method(rb_cListDigraph, "initialize", RUBY_METHOD_FUNC(wrap_ListDigraph_initialize), 0);  
	rb_define_method(rb_cListDigraph, "clear", RUBY_METHOD_FUNC(wrap_ListDigraph_clear), 0);  
	rb_define_method(rb_cListDigraph, "add_node", RUBY_METHOD_FUNC(wrap_ListDigraph_addNode), 0); 
	rb_define_method(rb_cListDigraph, "erase_node", RUBY_METHOD_FUNC(wrap_ListDigraph_erase), 1);  
	rb_define_method(rb_cListDigraph, "node_count", RUBY_METHOD_FUNC(wrap_ListDigraph_countNodes), 0);  

	rb_cListDigraphNode = rb_define_class_under(rb_cListDigraph, "Node", rb_cObject);	
        
}