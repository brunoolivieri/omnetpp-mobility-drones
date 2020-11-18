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


network omnetpp802154
{
	parameters:
    	int numHosts;
        @display("bgb=1000,1000");
    //@display("bgb=20,20;bgi=showcases/floorplan,s");
    submodules:
        visualizer: IntegratedMultiVisualizer { // original IntegratedVisualizer
            @display("p=-100,-50");
        }
        host[numHosts]: StandardHost {  // original StandardHost
            @display("i=misc/node_vs");
        }
        
        
        sensor1: SensorNode {
            @display("p=9.5,3.5;i=misc/sensor");
        }
        controller: SensorNode {
            @display("p=6.5,10.5;i=misc/sensorgateway");
        }
        configurator: Ipv4NetworkConfigurator {
            @display("p=18,0.75");
        }
        radioMedium: Ieee802154NarrowbandScalarRadioMedium {
            @display("p=18,2.25");
        }
        //visualizer: IntegratedMultiVisualizer {
        //    @display("p=18,3.75");
        //}
}
