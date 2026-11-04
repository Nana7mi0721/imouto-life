
int FUN_00575520(byte *param_1,uint param_2,undefined1 *param_3,int param_4)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int local_4;
  
  iVar4 = 0;
  local_4 = 0;
  if (param_4 == 0) {
    return 0;
  }
  if ((int)param_2 < 0) {
LAB_00575547:
    if ((byte)((*param_1 ^ 0x20) + 0x5f) < 0x3c) {
      pbVar1 = param_1 + 2;
      uVar2 = (uint)CONCAT11(*param_1,param_1[1]);
    }
    else {
      uVar2 = (uint)*param_1;
      if (uVar2 == 0) goto LAB_00575606;
      pbVar1 = param_1 + 1;
    }
    param_1 = pbVar1;
    if (((ushort)(&DAT_00b239c4)[uVar2] < 0x100) && (1 < (uint)(param_4 - iVar4))) {
      if (param_3 != (undefined1 *)0x0) {
        *param_3 = (char)(&DAT_00b239c4)[uVar2];
        param_3 = param_3 + 1;
      }
      iVar4 = iVar4 + 1;
    }
    goto LAB_00575547;
  }
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      if ((byte)((*param_1 ^ 0x20) + 0x5f) < 0x3c) {
        pbVar1 = param_1 + 2;
        uVar2 = uVar2 + 2;
        uVar3 = (uint)CONCAT11(*param_1,param_1[1]);
      }
      else {
        uVar3 = (uint)*param_1;
        if (uVar3 == 0) break;
        pbVar1 = param_1 + 1;
        uVar2 = uVar2 + 1;
      }
      if ((ushort)(&DAT_00b239c4)[uVar3] < 0x100) {
        if ((uint)(param_4 - local_4) < 2) {
          iVar4 = local_4;
        }
        else {
          if (param_3 != (undefined1 *)0x0) {
            *param_3 = (char)(&DAT_00b239c4)[uVar3];
            param_3 = param_3 + 1;
          }
          local_4 = local_4 + 1;
          iVar4 = local_4;
        }
      }
      param_1 = pbVar1;
    } while (uVar2 < param_2);
  }
LAB_00575606:
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = 0;
  }
  return iVar4 + 1;
}

