
using System;

namespace ControlInstrument {
    /// <summary>
    /// VISA対応/非対応測定器の差を吸収するためのインターフェース
    /// </summary>
    interface IInstrument : IDisposable {

        void SendCommand(string command);

        string ReadCommand(string command);

        string SendAndRead(string command);
    }
}
