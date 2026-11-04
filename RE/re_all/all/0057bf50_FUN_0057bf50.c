
undefined4 FUN_0057bf50(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  tagMSG local_1c;
  
  if ((DAT_00ca3cec != (HWND)0x0) && (DAT_00ca3cd8 != 0)) {
    if (DAT_00cc6240 != 0) {
      FUN_0056da60(&DAT_00cc6284,"..\\..\\..\\..\\Source\\Library\\Main\\DxNetwork.cpp",0xcc);
    }
    if (param_1 == 1) {
      iVar3 = DAT_00cc6254[3];
      puVar2 = DAT_00cc6254;
      while (iVar3 != 0) {
        iVar3 = puVar2[1];
        puVar1 = (undefined4 *)puVar2[3];
        if (((*(int *)(iVar3 + 0x38) == 1) &&
            ((((*(int *)(iVar3 + 0x48) == 0 && (*(int *)(iVar3 + 0x4c) == 1)) &&
              (*(int *)(iVar3 + 0x5c) == 1)) || (*(int *)(iVar3 + 0x40) == 1)))) &&
           (DAT_00ca3cd8 != 0)) {
          FUN_00580b80(*puVar2);
        }
        puVar2 = puVar1;
        iVar3 = puVar1[3];
      }
    }
    iVar3 = PeekMessageW(&local_1c,DAT_00ca3cec,0,0,1);
    while (iVar3 != 0) {
      TranslateMessage(&local_1c);
      DispatchMessageW(&local_1c);
      iVar3 = PeekMessageW(&local_1c,DAT_00ca3cec,0,0,1);
    }
    if (DAT_00cc6240 != 0) {
      FUN_0056dac0(&DAT_00cc6284);
    }
  }
  return 0;
}

