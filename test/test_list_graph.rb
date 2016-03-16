require "test/unit"
require File.expand_path('../../lib/ruby_lemon', __FILE__)

class TestListGraph < Test::Unit::TestCase

  def test_list_di_graph
    graph = Lemon::ListDigraph.new
    n1 = graph.add_node()
    
    puts n1
    puts graph

    puts "Size : #{graph.node_count}"
    puts graph.erase_node(n1)
    puts "Size : #{graph.node_count}"



    graph.clear()

    
  end 


end
