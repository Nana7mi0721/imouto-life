
int FUN_00575820(byte *param_1,uint param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  int local_4;
  
  iVar1 = param_4;
  uVar3 = param_2;
  iVar2 = 0;
  local_4 = 0;
  if (param_4 == 0) {
    return iVar2;
  }
  if ((int)param_2 < 0) {
    do {
      if ((byte)((*param_1 ^ 0x20) + 0x5f) < 0x3c) {
        pbVar5 = param_1 + 2;
        uVar3 = (uint)CONCAT11(*param_1,param_1[1]);
      }
      else {
        uVar3 = (uint)*param_1;
        if (uVar3 == 0) goto LAB_005758f8;
        pbVar5 = param_1 + 1;
      }
      param_1 = (byte *)(uint)(ushort)(&DAT_00b239c4)[uVar3];
      FUN_00573e90(&param_3,&param_1,&local_4,iVar1);
      param_1 = pbVar5;
    } while( true );
  }
  uVar6 = 0;
  if (param_2 != 0) {
    do {
      if ((byte)((*param_1 ^ 0x20) + 0x5f) < 0x3c) {
        pbVar5 = param_1 + 2;
        uVar6 = uVar6 + 2;
        uVar4 = (uint)CONCAT11(*param_1,param_1[1]);
      }
      else {
        uVar4 = (uint)*param_1;
        if (uVar4 == 0) break;
        pbVar5 = param_1 + 1;
        uVar6 = uVar6 + 1;
      }
      param_1 = (byte *)(uint)(ushort)(&DAT_00b239c4)[uVar4];
      FUN_00573e90(&param_3,&param_1,&local_4,iVar1);
      param_1 = pbVar5;
    } while (uVar6 < uVar3);
LAB_005758f8:
    iVar2 = local_4;
  }
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = 0;
  }
  return iVar2 + 1;
}

