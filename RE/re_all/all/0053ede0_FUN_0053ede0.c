
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0053ede0(int param_1,double param_2,double param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,int param_7,undefined4 param_8,int param_9)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  int local_60 [2];
  undefined4 local_58;
  undefined4 local_54;
  double local_50;
  double local_48;
  int local_40;
  int local_30;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_8;
  int local_4;
  
  FUN_0053e820(param_7,param_4,param_5,param_6,param_8,param_9,local_60,&local_54);
  iVar2 = local_60[0];
  if (param_9 == 0) {
    local_40 = param_1;
    local_48 = (double)local_4 * param_3;
    local_60[0] = (int)ROUND(local_48);
    iVar2 = local_60[0] + 3;
    FUN_00514e10(&local_40,&local_20);
    DAT_00a38194 = local_40;
    DAT_00a3819c = (int)ROUND((double)local_8 * param_2) + 3 + param_1;
    DAT_00a381a0 = iVar2 + unaff_EDI;
    FUN_005811b0(&local_40);
    local_30 = param_1;
  }
  else {
    local_48 = (double)param_1;
    local_40 = (int)ROUND(local_48 -
                          (double)(int)(local_60[0] - (uint)*(ushort *)(param_7 + 0x93164)) *
                          param_2);
    iVar3 = (int)ROUND((double)local_8 * param_2) + 3 + local_40;
    local_50 = (double)local_4 * param_3;
    local_60[0] = (int)ROUND(local_50);
    iVar1 = local_60[0] + 3;
    FUN_00514e10(&local_40,&local_20);
    DAT_00a38194 = local_40;
    DAT_00a3819c = iVar3;
    DAT_00a381a0 = iVar1 + unaff_EDI;
    FUN_005811b0(&local_40);
    local_30 = (int)ROUND(local_48 -
                          (double)(int)(iVar2 - (uint)*(ushort *)(param_7 + 0x93164)) * param_2);
  }
  local_48 = (double)DAT_00a37e64 * param_3;
  local_60[0] = (int)ROUND(local_48);
  FUN_006ea010(DAT_00a37e58,local_58,&local_30,1,DAT_00a37e5c);
  DAT_00a38198 = local_1c;
  DAT_00a38194 = local_20;
  DAT_00a3819c = local_18;
  DAT_00a381a0 = local_14;
  FUN_005811b0(&local_20);
  _DAT_00a38114 = local_54;
  return 0;
}

