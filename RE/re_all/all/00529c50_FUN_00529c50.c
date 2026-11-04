
void FUN_00529c50(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_198 [74];
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  FUN_0056d380(local_198,0,400);
  puVar2 = local_198;
  for (iVar1 = 0x4a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  local_70 = param_2;
  local_60 = param_4;
  local_5c = param_5;
  local_6c = param_3;
  local_54 = param_7;
  local_14 = param_8;
  local_58 = param_6;
  local_10 = param_9;
  local_c = 0;
  FUN_005291f0(local_198,param_10,0);
  return;
}

