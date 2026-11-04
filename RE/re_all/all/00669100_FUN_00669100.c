
undefined4 *
FUN_00669100(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_36c [16];
  undefined1 *local_32c;
  undefined1 *local_328;
  undefined4 local_324;
  undefined1 *local_2c8;
  code *local_2c4;
  undefined4 *local_2c0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined1 local_44 [64];
  
  puVar2 = local_36c;
  for (iVar1 = 0xca; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_dc = 0x7fffffff;
  local_d8 = 0x7fffffff;
  local_d4 = 0;
  local_d0 = 0;
  FUN_0066cbb0(local_36c,param_5,param_6,param_7);
  FUN_00668dd0(local_36c,param_2,param_3,param_4);
  iVar1 = __setjmp3(local_44,0);
  if (iVar1 == 0) {
    local_328 = local_44;
    local_324 = 0;
    local_32c = &LAB_006c5890;
    iVar1 = FUN_00668fc0(local_36c,param_1);
    if (iVar1 != 0) {
      local_2c0 = (undefined4 *)FUN_0066cb30(local_36c,0x328);
      if (local_2c0 != (undefined4 *)0x0) {
        local_328 = (undefined1 *)0x0;
        local_324 = 0;
        local_32c = (undefined1 *)0x0;
        local_2c8 = &LAB_00668ec0;
        local_2c4 = FUN_00668f10;
        puVar2 = local_36c;
        puVar3 = local_2c0;
        for (iVar1 = 0xca; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar3 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar3 = puVar3 + 1;
        }
        return local_2c0;
      }
    }
  }
  return (undefined4 *)0x0;
}

