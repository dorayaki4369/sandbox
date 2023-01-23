using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Ivi.Visa;

namespace ControlInstrument {
    class Dmm : IInstrument {
        private readonly IMessageBasedSession _session;
        public Dmm(string visaAddress) {
            _session = (IMessageBasedSession) GlobalResourceManager.Open(visaAddress);
        }

        public void Dispose() {
            _session.Dispose();
        }

        public void SendCommand(string command) {
            _session.FormattedIO.WriteLine(command);
        }

        public string ReadCommand(string command) {
            return _session.FormattedIO.ReadLine();
        }

        public string SendAndRead(string command) {
            SendCommand(command);
            return ReadCommand(command);
        }
    }
}
