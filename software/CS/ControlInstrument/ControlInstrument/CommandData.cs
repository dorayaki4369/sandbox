using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;

namespace ControlInstrument
{
    class CommandData
    {
        [JsonProperty("VisaAddress")]
        public string VisaAddress { get; set; }

        [JsonProperty("CommandList")]
        public List<string> CommandList { get; set; }
    }
}
