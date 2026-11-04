
int FUN_00575a20(byte *param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  undefined2 uVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  if (param_4 < 4) {
    return 0;
  }
  if ((int)param_2 < 0) {
LAB_00575a44:
    if ((byte)((*param_1 ^ 0x20) + 0x5f) < 0x3c) {
      pbVar2 = param_1 + 2;
      uVar3 = (uint)CONCAT11(*param_1,param_1[1]);
    }
    else {
      uVar3 = (uint)*param_1;
      if (uVar3 == 0) goto LAB_00575b17;
      pbVar2 = param_1 + 1;
    }
    uVar1 = (&DAT_00b239c4)[uVar3];
    param_1 = pbVar2;
    if (7 < param_4 - iVar5) {
      if (param_3 != (undefined4 *)0x0) {
        *(undefined1 *)param_3 = 0;
        *(undefined1 *)((int)param_3 + 1) = 0;
        *(char *)((int)param_3 + 2) = (char)((ushort)uVar1 >> 8);
        *(char *)((int)param_3 + 3) = (char)uVar1;
        param_3 = param_3 + 1;
      }
      iVar5 = iVar5 + 4;
    }
    goto LAB_00575a44;
  }
  uVar3 = 0;
  if (param_2 != 0) {
    do {
      if ((byte)((*param_1 ^ 0x20) + 0x5f) < 0x3c) {
        pbVar2 = param_1 + 2;
        uVar3 = uVar3 + 2;
        uVar4 = (uint)CONCAT11(*param_1,param_1[1]);
      }
      else {
        uVar4 = (uint)*param_1;
        if (uVar4 == 0) break;
        pbVar2 = param_1 + 1;
        uVar3 = uVar3 + 1;
      }
      uVar1 = (&DAT_00b239c4)[uVar4];
      if (7 < param_4 - iVar5) {
        if (param_3 != (undefined4 *)0x0) {
          *(undefined1 *)param_3 = 0;
          *(undefined1 *)((int)param_3 + 1) = 0;
          *(char *)((int)param_3 + 2) = (char)((ushort)uVar1 >> 8);
          *(char *)((int)param_3 + 3) = (char)uVar1;
          param_3 = param_3 + 1;
        }
        iVar5 = iVar5 + 4;
      }
      param_1 = pbVar2;
    } while (uVar3 < param_2);
  }
LAB_00575b17:
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  return iVar5 + 4;
}

