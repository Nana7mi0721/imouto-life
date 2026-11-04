
undefined4 FUN_0064bf60(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = (1 << ((byte)param_1[6] & 0x1f)) + -1;
  if ((short)param_1[6] == 0x10) {
    iVar5 = 0xff;
  }
  iVar1 = FUN_006507d0(iVar5 + 1);
  param_1[0xe] = iVar1;
  if (iVar1 == 0) {
    uVar2 = FUN_006507b0(*param_1,s_No_space_for_photometric_convers_00a0663c);
    FUN_006512e0(*(undefined4 *)(*param_1 + 0x274),uVar2);
    return 0;
  }
  if ((short)param_1[8] == 0) {
    if (-1 < iVar5) {
      iVar1 = 0;
      iVar4 = iVar5 * 0xff;
      do {
        iVar3 = iVar1 + 1;
        *(char *)(iVar1 + param_1[0xe]) = (char)(iVar4 / iVar5);
        iVar1 = iVar3;
        iVar4 = iVar4 + -0xff;
      } while (iVar3 <= iVar5);
    }
  }
  else if (-1 < iVar5) {
    iVar1 = 0;
    iVar4 = 0;
    do {
      iVar3 = iVar1 + 1;
      *(char *)(iVar1 + param_1[0xe]) = (char)(iVar4 / iVar5);
      iVar1 = iVar3;
      iVar4 = iVar4 + 0xff;
    } while (iVar3 <= iVar5);
  }
  if ((*(ushort *)(param_1 + 6) < 0x11) && (((short)param_1[8] == 1 || ((short)param_1[8] == 0)))) {
    iVar5 = FUN_0064c050(param_1);
    if (iVar5 == 0) {
      return 0;
    }
    FUN_006507e0(param_1[0xe]);
    param_1[0xe] = 0;
  }
  return 1;
}

