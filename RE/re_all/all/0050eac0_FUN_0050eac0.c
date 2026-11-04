
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0050eac0(uint param_1)

{
  LPCWSTR lpIconName;
  HICON dwNewLong;
  
  _DAT_00a24d48 = param_1;
  if (DAT_00a20bec != (HWND)0x0) {
    if (param_1 == 0) {
      lpIconName = (LPCWSTR)0x7f00;
    }
    else {
      lpIconName = (LPCWSTR)(param_1 & 0xffff);
    }
    dwNewLong = LoadIconW(DAT_00a20be8,lpIconName);
    SetClassLongW(DAT_00a20bec,-0xe,(LONG)dwNewLong);
  }
  return 0;
}

