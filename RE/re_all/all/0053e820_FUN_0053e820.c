
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0053e820(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,int param_6,
            int *param_7,undefined4 *param_8)

{
  int *piVar1;
  undefined4 *in_EAX;
  undefined *puVar2;
  int iVar3;
  int *unaff_EBX;
  undefined4 *unaff_ESI;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  int local_4;
  
  FUN_00537710(0,0,0,0,0,1,0,0x3ff0000000000000,0x3ff0000000000000,0,0,0,0,param_2,0,0,0,0,param_1,0
               ,param_3,param_6,param_7,0,0,0,0,0);
  puVar2 = &DAT_00a37e40;
  if ((*(byte *)(param_1 + 0x93184) & 2) == 0) {
    puVar2 = &DAT_00a37e28;
  }
  *unaff_EBX = (int)puVar2;
  *in_EAX = DAT_00a38194;
  in_EAX[1] = DAT_00a38198;
  in_EAX[2] = DAT_00a3819c;
  in_EAX[3] = DAT_00a381a0;
  *param_8 = _DAT_00a38114;
  local_14 = DAT_00a37e64;
  local_18 = DAT_00a37e60;
  *unaff_ESI = 0;
  iVar3 = *param_7;
  unaff_ESI[1] = 0;
  local_1c = 0;
  local_20 = 0;
  unaff_ESI[2] = iVar3;
  unaff_ESI[3] = param_7[1];
  FUN_00514e10();
  DAT_00a38194 = *unaff_ESI;
  DAT_00a38198 = unaff_ESI[1];
  DAT_00a3819c = unaff_ESI[2];
  DAT_00a381a0 = unaff_ESI[3];
  FUN_005811b0();
  if ((*(byte *)(param_1 + 0x93184) & 2) == 0) {
    while( true ) {
      iVar3 = *(int *)(*(int *)(*unaff_EBX + 0x14) + 0x1c);
      if ((param_4 != iVar3) && (param_5 != iVar3)) break;
      piVar1 = (int *)(*(int *)(*unaff_EBX + 0x14) + 0x1c);
      *piVar1 = *piVar1 + 1;
    }
  }
  else {
    *(undefined4 *)(*(int *)(*unaff_EBX + 0x14) + 0x1c) = 0;
  }
  local_c = unaff_ESI[1];
  local_10 = *unaff_ESI;
  local_4 = unaff_ESI[3] + 4;
  local_8 = unaff_ESI[2] + 4;
  FUN_00514e10(&local_10,&local_20);
  FUN_00581fb0(*unaff_EBX,&local_10,*(undefined4 *)(*(int *)(*unaff_EBX + 0x14) + 0x1c));
  if (param_6 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *param_7 - (uint)*(ushort *)(param_1 + 0x93164);
  }
  FUN_00537710(1,iVar3,0,0,0,1,0,0x3ff0000000000000,0x3ff0000000000000,0,0,0,0,param_2,param_4,
               *unaff_EBX);
  _DAT_00a38114 = 0xffffff;
  return 0;
}

