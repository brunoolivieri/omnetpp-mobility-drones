// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 
package inet.showcases.mobilityDrones;

import inet.common.geometry.common.OsgGeographicCoordinateSystem;
import inet.environment.common.PhysicalEnvironment;
import inet.node.inet.AdhocHost;
import inet.visualizer.integrated.IntegratedVisualizer;
import inet.mobility.contract.IMobility;
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


network mobilityDrones
{
    parameters:
//        @display("bgb=$playgroundWidth,$playgroundHeight;bgi=background/terrain,s");
//        double playgroundLatitude; // geographic position of the playground's north-west corner
//        double playgroundLongitude; // geographic position of the playground's north-west corner
//        double playgroundWidth @unit("m") = default(500m);  // the E-W size of playground
//        double playgroundHeight @unit("m") = default(500m); // the N-S size of playground
//        int numUAVs = default(0);  // the number of UAVs in the field
//        int numCSs = default(0);  // the number of charging stations in the field
		int numUAVs = default(3);
		//coordinateSystemModule = "OsgGeographicCoordinateSystem";
        double initialLatitude @unit(deg) = default(nan deg);
        double initialLongitude @unit(deg) = default(nan deg);
        double initialAltitude @unit(m) = default(0m);  

    types:
//        channel Channel extends ned.DelayChannel {
//            delay = 1ms;
//        }
    submodules:
        visualizer: IntegratedVisualizer {
            parameters:
                @display("p=100,50");
        }
        coordinateSystem: OsgGeographicCoordinateSystem {
            parameters:
                @display("p=100,150");
        }   
        configurator: Ipv4NetworkConfigurator {
            @display("p=0,200");
        }
        radioMedium: Ieee802154NarrowbandScalarRadioMedium {
            @display("p=200,0");
        }
        drones[numUAVs]: MobileNode {//MobileNode { // Last Commit AdhocHost {  // original StandardHost
            //@display("i=misc/node_vs");
        }             

}
