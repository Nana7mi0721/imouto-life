
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004465e0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  if (DAT_00a14581 == '\0') {
    puVar2 = &param_2;
    puVar1 = (undefined4 *)FUN_004ce060(local_8);
    FUN_004ce220(local_c,*puVar1,puVar2);
  }
  else {
    _DAT_00a14584 = param_2;
  }
  *(undefined1 *)(param_1 + 0xc0) = 1;
  return;
}

