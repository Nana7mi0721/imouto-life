
undefined4 FUN_0057ffd0(int param_1)

{
  DWORD DVar1;
  DWORD DVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  
  FUN_0056da60(&DAT_00ca4230,"..\\..\\..\\..\\Source\\Library\\Main\\DxASyncLoad.cpp",0x3bb);
  if (DAT_00ca44d0 == 0x8000) {
    puVar5 = &DAT_007d98d8;
  }
  else {
    iVar4 = 0;
    (&DAT_00ca4450)[DAT_00ca44d0] = param_1;
    *(undefined4 *)(param_1 + 8) = 0;
    DVar1 = GetCurrentThreadId();
    puVar5 = &DAT_00ca3d2c;
    do {
      DVar2 = FUN_0052d190(puVar5);
      if (DVar2 == DVar1) break;
      iVar4 = iVar4 + 1;
      puVar5 = puVar5 + 0x28;
    } while (iVar4 < 0x20);
    if (iVar4 != 0x20) {
      *(int *)(param_1 + 4) = iVar4;
      *(undefined4 *)(puVar5 + 0x18) = 1;
      DAT_00ca44d0 = DAT_00ca44d0 + 1;
      FUN_0057fd00(1);
      *(undefined4 *)(puVar5 + 0x1c) = 1;
      uVar3 = FUN_00550060(0);
      *(undefined4 *)(puVar5 + 0x20) = uVar3;
      DAT_00ca422c = DAT_00ca422c + -1;
      FUN_0056dac0(&DAT_00ca4230);
      FUN_0056d9f0(puVar5);
      return *(undefined4 *)(param_1 + 8);
    }
    puVar5 = &DAT_007d9890;
  }
  FUN_0056bb10(puVar5);
  FUN_0056dac0(&DAT_00ca4230);
  return 0xffffffff;
}

