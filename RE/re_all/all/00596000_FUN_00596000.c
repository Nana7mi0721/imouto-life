
undefined4 FUN_00596000(int param_1)

{
  DAT_00ddb2f0 = CreateCompatibleDC((HDC)0x0);
  if (DAT_00ddb2f0 == (HDC)0x0) {
    FUN_0056bb10(&DAT_007d9df8);
    return 0xffffffff;
  }
  DAT_00ddb2f4 = SelectObject(DAT_00ddb2f0,*(HGDIOBJ *)(*(int *)(param_1 + 0x30) + 0x10));
  if (DAT_00ddb2f4 == (HGDIOBJ)0x0) {
    DeleteDC(DAT_00ddb2f0);
    FUN_0056bb10(&DAT_007d9df8);
    return 0xffffffff;
  }
  GetTextMetricsA(DAT_00ddb2f0,(LPTEXTMETRICA)&DAT_00ddb2fc);
  if (**(int **)(param_1 + 0x30) != 0) {
    DAT_00ddb2f8 = SelectObject(DAT_00ddb2f0,(HGDIOBJ)(*(int **)(param_1 + 0x30))[1]);
    SetTextColor(DAT_00ddb2f0,0xffffff);
    SetBkColor(DAT_00ddb2f0,0);
    SetBkMode(DAT_00ddb2f0,2);
  }
  return 0;
}

