
int FUN_00575910(byte *param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  
  iVar5 = 0;
  if (param_4 < 4) {
    return 0;
  }
  if ((int)param_2 < 0) {
LAB_00575934:
    if ((byte)((*param_1 ^ 0x20) + 0x5f) < 0x3c) {
      pbVar4 = param_1 + 2;
      uVar2 = (uint)CONCAT11(*param_1,param_1[1]);
    }
    else {
      uVar2 = (uint)*param_1;
      if (uVar2 == 0) goto LAB_00575a05;
      pbVar4 = param_1 + 1;
    }
    uVar1 = (&DAT_00b239c4)[uVar2];
    param_1 = pbVar4;
    if (7 < param_4 - iVar5) {
      if (param_3 != (undefined4 *)0x0) {
        *(char *)param_3 = (char)uVar1;
        *(char *)((int)param_3 + 1) = (char)((ushort)uVar1 >> 8);
        *(undefined1 *)((int)param_3 + 2) = 0;
        *(undefined1 *)((int)param_3 + 3) = 0;
        param_3 = param_3 + 1;
      }
      iVar5 = iVar5 + 4;
    }
    goto LAB_00575934;
  }
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      if ((byte)((*param_1 ^ 0x20) + 0x5f) < 0x3c) {
        pbVar4 = param_1 + 2;
        uVar2 = uVar2 + 2;
        uVar3 = (uint)CONCAT11(*param_1,param_1[1]);
      }
      else {
        uVar3 = (uint)*param_1;
        if (uVar3 == 0) break;
        pbVar4 = param_1 + 1;
        uVar2 = uVar2 + 1;
      }
      uVar1 = (&DAT_00b239c4)[uVar3];
      if (7 < param_4 - iVar5) {
        if (param_3 != (undefined4 *)0x0) {
          *(char *)param_3 = (char)uVar1;
          *(char *)((int)param_3 + 1) = (char)((ushort)uVar1 >> 8);
          *(undefined1 *)((int)param_3 + 2) = 0;
          *(undefined1 *)((int)param_3 + 3) = 0;
          param_3 = param_3 + 1;
        }
        iVar5 = iVar5 + 4;
      }
      param_1 = pbVar4;
    } while (uVar2 < param_2);
  }
LAB_00575a05:
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  return iVar5 + 4;
}

