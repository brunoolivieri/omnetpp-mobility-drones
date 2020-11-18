package inet.showcases.mobilityDrones;

// default
import inet.node.inet.StandardHost;
import inet.visualizer.integrated.IntegratedVisualizer;

// comes from Ieee802.15.4
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.ethernet.Eth100M;
import inet.node.inet.SensorNode;
import inet.node.inet.StandardHost;
import inet.node.inet.WirelessHost;
import inet.physicallayer.apskradio.packetlevel.ApskScalarRadioMedium;
import inet.physicallayer.ieee802154.bitlevel.Ieee802154UwbIrRadioMedium;
import inet.physicallayer.ieee802154.packetlevel.Ieee802154NarrowbandScalarRadioMedium;
import inet.visualizer.integrated.IntegratedMultiVisualizer;
import inet.visualizer.integrated.IntegratedVisualizer;
////////////////////////////////////////////////////////////////

network mobilityDrones
{
    parameters:
        int numHosts;
        @display("bgb=1000,1000");
    submodules:
        visualizer: IntegratedMultiVisualizer { // original IntegratedVisualizer
            @display("p=-100,-50");
        }
        host[numHosts]: SensorNode {  // original StandardHost
            @display("i=misc/node_vs");
        }
        sensor1: SensorNode {
            @display("p=50,50;i=misc/sensor");
        }
      configurator: Ipv4NetworkConfigurator {
            @display("p=0,200");
        }
        radioMedium: Ieee802154NarrowbandScalarRadioMedium {
            @display("p=200,0");
        }
        
        
        
}
