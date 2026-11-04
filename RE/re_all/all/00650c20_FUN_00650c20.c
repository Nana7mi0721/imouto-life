
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00650c20(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_0064e2e0(param_1,param_2,param_3);
  if (iVar1 != 0) {
    return 1;
  }
  if (param_2 < 0x13f) {
    if (param_2 == 0x13e) {
      _DAT_00f3fa50 = 0x3eb10516;
      _DAT_00f3fa54 = 0x3eb7953c;
      *(undefined **)*param_3 = &DAT_00f3fa50;
      return 1;
    }
    switch(param_2) {
    case 0xfe:
      *(undefined4 *)*param_3 = param_1[0x14];
      return 1;
    case 0x102:
      *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x15);
      return 1;
    case 0x107:
      *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x17);
      return 1;
    case 0x10a:
      *(undefined2 *)*param_3 = *(undefined2 *)((int)param_1 + 0x5e);
      return 1;
    case 0x112:
      *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x18);
      return 1;
    case 0x115:
      *(undefined2 *)*param_3 = *(undefined2 *)((int)param_1 + 0x62);
      return 1;
    case 0x116:
      *(undefined4 *)*param_3 = param_1[0x19];
      return 1;
    case 0x118:
      *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x1a);
      return 1;
    case 0x119:
      *(undefined2 *)*param_3 = *(undefined2 *)((int)param_1 + 0x6a);
      return 1;
    case 0x11c:
      *(undefined2 *)*param_3 = *(undefined2 *)((int)param_1 + 0x7e);
      return 1;
    case 0x128:
      *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x1f);
      return 1;
    case 0x12d:
      if ((param_1[0x32] == 0) && (iVar1 = FUN_00651050(param_1 + 10), iVar1 == 0)) {
        FUN_006512e0(param_1[0x9d],*param_1,s_No_space_for__TransferFunction__t_00a06bbc);
        return 0;
      }
      *(undefined4 *)*param_3 = param_1[0x32];
      if ((int)((uint)*(ushort *)((int)param_1 + 0x62) - (uint)*(ushort *)(param_1 + 0x27)) < 2) {
        return 1;
      }
      *(undefined4 *)param_3[1] = param_1[0x33];
      *(undefined4 *)param_3[2] = param_1[0x34];
      return 1;
    case 0x13d:
      *(undefined2 *)*param_3 = *(undefined2 *)param_1[0x90];
      return 1;
    }
  }
  else if (param_2 < 0x212) {
    if (param_2 == 0x211) {
      *(undefined **)*param_3 = &DAT_00a06b6c;
      return 1;
    }
    switch(param_2) {
    case 0x14c:
      *(undefined2 *)*param_3 = 1;
      return 1;
    case 0x14e:
      *(undefined2 *)*param_3 = 4;
      return 1;
    case 0x150:
      *(undefined2 *)*param_3 = 0;
      *(short *)param_3[1] = (short)(1 << (*(byte *)(param_1 + 0x15) & 0x1f)) + -1;
      return 1;
    case 0x152:
      *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x27);
      *(undefined4 *)param_3[1] = param_1[0x28];
      return 1;
    case 0x153:
      *(undefined2 *)*param_3 = *(undefined2 *)((int)param_1 + 0x56);
      return 1;
    }
  }
  else if (param_2 < 0x80e4) {
    if (param_2 == 0x80e3) {
      if ((*(short *)(param_1 + 0x27) == 1) && (*(short *)param_1[0x28] == 1)) {
        *(undefined2 *)*param_3 = 1;
        return 1;
      }
      *(undefined2 *)*param_3 = 0;
      return 1;
    }
    if (param_2 == 0x212) {
      *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x30);
      *(undefined2 *)param_3[1] = *(undefined2 *)((int)param_1 + 0xc2);
      return 1;
    }
    if (param_2 == 0x213) {
      *(undefined2 *)*param_3 = *(undefined2 *)(param_1 + 0x31);
      return 1;
    }
    if (param_2 == 0x214) {
      if ((param_1[0x35] == 0) && (iVar1 = FUN_006511e0(param_1 + 10), iVar1 == 0)) {
        return 0;
      }
      *(undefined4 *)*param_3 = param_1[0x35];
      return 1;
    }
  }
  else {
    if (param_2 == 0x80e4) {
      *(short *)*param_3 = *(short *)((int)param_1 + 0x56) + -1;
      return 1;
    }
    if (param_2 == 0x80e5) {
      *(undefined4 *)*param_3 = param_1[0x10];
      return 1;
    }
    if (param_2 == 0x80e6) {
      *(undefined4 *)*param_3 = param_1[0x13];
      return 1;
    }
  }
  return 0;
}

