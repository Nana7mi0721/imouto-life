
undefined4 FUN_0057c9b0(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 1;
  if (DAT_00cc6240 != 0) {
    FUN_0056da60(&DAT_00cc6284,"..\\..\\..\\..\\Source\\Library\\Main\\DxNetwork.cpp",0x1e9);
  }
  iVar1 = *(int *)(DAT_00cc6254 + 0xc);
  iVar3 = DAT_00cc6254;
  while ((iVar2 = iVar1, iVar2 != 0 && (*(int *)(*(int *)(iVar3 + 4) + 0x60) != param_3))) {
    iVar1 = *(int *)(iVar2 + 0xc);
    iVar3 = iVar2;
  }
  iVar1 = *(int *)(iVar3 + 4);
  if (*(int *)(iVar3 + 0xc) == 0) {
    if (DAT_00cc6240 != 0) {
      FUN_0056dac0(&DAT_00cc6284);
    }
    FUN_0056bb10(&DAT_007d8540);
    return 0;
  }
  if (*(int *)(iVar1 + 0x30) == 0) {
    switch(param_4 & 0xffff) {
    case 1:
      FUN_0057c450();
      break;
    case 2:
      FUN_0057c6f0();
      break;
    case 8:
      uVar4 = FUN_0057c150();
      break;
    case 0x10:
      if ((short)(param_4 >> 0x10) == 0) {
        *(undefined4 *)(iVar1 + 0x48) = 1;
        *(undefined4 *)(iVar1 + 0x44) = 0;
      }
      break;
    case 0x20:
      *(undefined4 *)(iVar1 + 0x48) = 0;
      *(undefined4 *)(iVar1 + 0x4c) = 0;
    }
  }
  else if ((param_4 & 0xffff) == 1) {
    *(undefined4 *)(iVar1 + 0xb8) = 1;
  }
  else if ((param_4 & 0xffff) == 2) {
    *(undefined4 *)(iVar1 + 0xbc) = 1;
  }
  if (DAT_00cc6240 != 0) {
    FUN_0056dac0(&DAT_00cc6284);
  }
  return uVar4;
}

