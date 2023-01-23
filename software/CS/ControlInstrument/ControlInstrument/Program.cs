using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Ivi.Visa;
using Newtonsoft.Json;

namespace ControlInstrument {
    class Program {
        static void Main(string[] args) {
            Console.WriteLine("Jsonファイルのパスを入力してください。");
            //var path = Console.ReadLine();
            var path = @"C:\Users\0048006001\Desktop\command_dmm.json";

            var reader = new StreamReader(path ?? throw new InvalidOperationException());
            var data   = JsonConvert.DeserializeObject<CommandData>(reader.ReadToEnd());
            reader.Dispose();


            using (var session =
                (IMessageBasedSession) GlobalResourceManager.Open(data.VisaAddress)) {
                foreach (var command in data.CommandList) {
                    session.FormattedIO.WriteLine(command);

                    if (command.Contains("?")) {
                        var result = session.FormattedIO.ReadLine();
                        Console.WriteLine($"{command} = {result}");
                    }
                    else {
                        Console.WriteLine($"Send {command}");
                    }
                }
            }

            var el = new TexioElectronicLoad(Connect.USB, 1, 1, 1);
            el.SendCommand("");

            Console.WriteLine("End");

            Console.ReadLine();
        }
    }
}
