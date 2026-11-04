
undefined4 FUN_0064beb0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  switch((short)param_1[8]) {
  case 2:
  case 5:
  case 6:
    if ((short)param_1[6] == 8) {
      return 1;
    }
  case 0:
  case 1:
    iVar1 = FUN_0064bf60(param_1);
    if (iVar1 == 0) {
      return 0;
    }
    break;
  case 3:
    iVar1 = FUN_0064c370(param_1);
    if (iVar1 == 0x10) {
      FUN_0064c3d0(param_1);
    }
    else {
      uVar2 = FUN_006507b0(*param_1,s_Assuming_8_bit_colormap_00a06624);
      FUN_00653460(*(undefined4 *)(*param_1 + 0x274),uVar2);
    }
    if ((*(ushort *)(param_1 + 6) < 9) && (iVar1 = FUN_0064c420(param_1), iVar1 == 0)) {
      return 0;
    }
  }
  return 1;
}

