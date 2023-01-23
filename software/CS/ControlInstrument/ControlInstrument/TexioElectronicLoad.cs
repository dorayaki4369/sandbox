using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ControlInstrument {
    public enum Connect {
        GPIB = 1,
        USB  = 2
    }

    public enum Channel {
        CH_A = 1,
        CH_B = 2,
        CH_C = 3,
        CH_D = 4
    }

    class TexioElectronicLoad : IInstrument {
        public int DeviceId { get; set; }

        public TexioElectronicLoad(Connect connect, int boardAddr, int pcAddr, int sysAddr) {
            var id = LW_DeviceOpen((int) connect, boardAddr, pcAddr, sysAddr);
            if (id <= 0) throw new Exception();
            DeviceId = id;
            DeviceInitializer();
        }

        public void Dispose() {
            DeviceInitializer();
            var i = LW_DeviceClose(DeviceId);
            if (i <= 0) throw new Exception();
        }

        public void SendCommand(string command) {
            LW_SetMainInput(DeviceId, 1);
        }

        public string ReadCommand(string command) {
            throw new NotImplementedException();
        }

        public string SendAndRead(string command) {
            throw new NotImplementedException();
        }

        public void DeviceInitializer() {
            LW_SetMainInput(DeviceId, 0);
            LW_SetInputSelect(DeviceId, 1, 1);
            LW_SetDisplaySelect(DeviceId, 1);
        }

        //
        //以下APIのIF_50.csをコピペして編集
        //

        // ********************************************************************************
        //   構造体宣言
        // ********************************************************************************
        // モニターデータ構造体
        [StructLayout(LayoutKind.Sequential)]
        public struct MonitorData {
            public double Current; // 電流モニター値
            public double Voltage; // 電圧モニター値
            public double Wattage; // 電力モニター値
        };

        // 放電負荷モード設定データ構造体
        [StructLayout(LayoutKind.Sequential)]
        public struct ModeData {
            public int Mode;      //放電負荷モード設定
            public int Reference; // コントロールリファレンス設定
        };

        // スイッチング時間設定データ構造体
        [StructLayout(LayoutKind.Sequential)]
        public struct TimeData {
            public double Ta; // 時間ｔａ設定
            public double Tb; // 時間ｔｂ設定
        };

        // トラッキング設定データ構造体
        [StructLayout(LayoutKind.Sequential)]
        public struct TrackData {
            public int Ch_A; // ＣＨ－Ａ
            public int Ch_B; // ＣＨ－Ｂ
            public int Ch_C; // ＣＨ－Ｃ
            public int Ch_D; // ＣＨ－Ｄ
        };

        // アラームデータ構造体
        [StructLayout(LayoutKind.Sequential)]
        public struct AlarmData {
            public int Eta; // 外部アラーム
            public int Oha; // オーバーヒートアラーム
            public int Ova_A;
            public int Ova_B;
            public int Ova_C;
            public int Ova_D;
            public int Oca_A;
            public int Oca_B;
            public int Oca_C;
            public int Oca_D;
            public int Ora_A;
            public int Ora_B;
            public int Ora_C;
            public int Ora_D;
        };

        // リミットデータ構造体
        [StructLayout(LayoutKind.Sequential)]
        public struct LimitData {
            public int Current_A;
            public int Current_B;
            public int Current_C;
            public int Current_D;
            public int Power_A;
            public int Power_B;
            public int Power_C;
            public int Power_D;
        };

        // ＣＨ実装データ構造体
        [StructLayout(LayoutKind.Sequential)]
        public struct ChData {
            public int Ch_A; // ＣＨ－Ａ
            public int Ch_B; // ＣＨ－Ｂ
            public int Ch_C; // ＣＨ－Ｃ
            public int Ch_D; // ＣＨ－Ｄ
        };

        // C++/CLI - LWインターフェース定義
        // 各関数の詳細はデバイスドライバ取扱説明書を参照。

        // デバイスのオープン
        [DllImport("IF_50.dll")]
        private static extern int LW_DeviceOpen(int classRenamed, int boardAdr, int pcAdr, int sysAdr);

        // デバイスハンドルのクローズ
        [DllImport("IF_50.dll")]
        private static extern int LW_DeviceClose(int deviceId);

        [DllImport("IF_50.dll")]
        private static extern int LW_DeviceRefresh(int deviceId);

        // タイムアウト時間の設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetTimeOut(int deviceId, int time);

        // メインインプットの設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetMainInput(int deviceId, int flag);

        // メインインプットの状態読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetMainInput(int deviceId);

        // インプットセレクトの設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetInputSelect(int deviceId, int ch, int flag);

        // インプットセレクトの状態読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetInputSelect(int deviceId, int ch);

        // プリセット指定の設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetPresetNumber(int deviceId, int preset);

        // プリセット指定の状態読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetPresetNumber(int deviceId);

        // プリセットデータのコピー指示
        [DllImport("IF_50.dll")]
        private static extern int LW_SavePreset(int deviceId, int src, int dest);

        // モニタデータの読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetMonitor(int deviceId, int ch, out MonitorData monitor);

        // モニタ表示の設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetMonitorSelect(int deviceId, int flag);

        // モニタ表示の状態読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetMonitorSelect(int deviceId);

        // 表示CHの設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetDisplaySelect(int deviceId, int ch);

        // 表示CHの状態読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetDisplaySelect(int deviceId);

        // 負荷モードの設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetLoadMode(int deviceId, int preset, int ch, int mode, int Ref);

        // 負荷モードの状態読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetLoadMode(int deviceId, int preset, int ch, out ModeData modeData);

        // 負荷設定値の設定
        [DllImport("IF_50.dll")]
        public static extern int LW_SetLoadValue(int deviceId, int preset, int ch, double data);

        // 負荷設定値の読出し
        [DllImport("IF_50.dll")]
        public static extern int LW_GetLoadValue(int deviceId, int preset, int ch, out double data);

        // 負荷設定値の設定（シーメンス値）
        [DllImport("IF_50.dll")]
        private static extern int LW_SetSiemensValue(int deviceId, int preset, int ch, int data);

        // 負荷設定値の読出し（シーメンス値）
        [DllImport("IF_50.dll")]
        private static extern int LW_GetSiemensValue(int deviceId, int preset, int ch, out int data);

        // 電流制限値の設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetCurrentLimit(int deviceId, int preset, int ch, double data);

        // 電流制限値の読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetCurrentLimit(int deviceId, int preset, int ch, out double data);

        // 負荷設定値の記憶指示
        [DllImport("IF_50.dll")]
        private static extern int LW_SaveLoadValue(int deviceId, int preset, int ch);

        // 電流制限値の記憶指示
        [DllImport("IF_50.dll")]
        private static extern int LW_SaveCurrentLimit(int deviceId, int preset, int ch);

        // 設定情報の記憶指示
        [DllImport("IF_50.dll")]
        private static extern int LW_SaveMemoryData(int deviceId, int objectRenamed);

        // スイッチング動作指定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetSwSelect(int deviceId, int ch, int flag);

        // スイッチング動作状態読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetSwSelect(int deviceId, int ch);

        // スイッチング周波数設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetSwFreq(int deviceId, int freq);

        // スイッチング周波数読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetSwFreq(int deviceId, out int freq);

        // デューティー値設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetSwDuty(int deviceId, int duty);

        // デューティー値読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetSwDuty(int deviceId, out int duty);

        // スイッチング時間設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetSwTime(int deviceId, double ta, double tb);

        // スイッチング時間読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetSwTime(int deviceId, out TimeData time);

        // スイッチング状態設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetSwMethod(int deviceId, int flag);

        // スイッチング状態読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetSwMethod(int deviceId);

        // ディレイ動作設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetDelayFunction(int deviceId, int flag);

        // ディレイ動作状態読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetDelayFunction(int deviceId);

        // ディレイ時間設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetDelayTime(int deviceId, int ch, double time);

        // ディレイ時間読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetDelayTime(int deviceId, int ch, out double time);

        // トラッキング動作設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetTrackFunction(int deviceId, int flag);

        // トラッキング動作情報読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetTrackFunction(int deviceId);

        // トラッキング方向設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetTrackDirection(int deviceId, int chA, int chB, int chC, int chD);

        // トラッキング方向状態読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetTrackDirection(int deviceId, out TrackData track);

        // トラッキングモード設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetTrackMode(int deviceId, int mode);

        // トラッキングモード読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetTrackMode(int deviceId);

        // トラッキング変位量設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetTrackValue(int deviceId, double data);

        // トラッキング変位量読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetTrackValue(int deviceId, out double data);

        // アラームクリア
        [DllImport("IF_50.dll")]
        private static extern int LW_ResetAlarm(int deviceId);

        // アラーム状態読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetAlarm(int deviceId, out AlarmData alarm);

        // リミット情報読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetLimit(int deviceId, out LimitData limit);

        // 操作タイムアウト時間の設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetOperationTimeOut(int deviceId, int time);

        // 操作タイムアウト時間の読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetOperationTimeOut(int deviceId);

        // ローカル状態への移行
        [DllImport("IF_50.dll")]
        private static extern int LW_SetLocal(int deviceId);

        // ローカルロックアウトの設定
        [DllImport("IF_50.dll")]
        private static extern int LW_SetLocalLockOut(int deviceId, int flag);

        // ローカルロックアウトの状態読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetLocalLockOut(int deviceId);

        // 本体IDの読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetIdNumber(int deviceId);

        // チャンネル装備状態の読出し
        [DllImport("IF_50.dll")]
        private static extern int LW_GetChExist(int deviceId, out ChData chData);
    }
}