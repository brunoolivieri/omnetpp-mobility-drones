package inet.showcases.mobilityDrones;

import inet.node.inet.StandardHost;
import inet.visualizer.integrated.IntegratedVisualizer;


network mobilityDrones
{
    parameters:
        int numHosts;
        @display("bgb=1000,1000");
    submodules:
        visualizer: IntegratedVisualizer {
            @display("p=100,50");
        }
        host[numHosts]: StandardHost {
            @display("i=misc/node_vs");
        }
}
