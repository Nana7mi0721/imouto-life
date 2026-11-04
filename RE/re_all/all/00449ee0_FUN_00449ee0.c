
void __fastcall FUN_00449ee0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int local_c;
  int local_8;
  
  if (-1 < *(int *)(param_1 + 0x1658)) {
    local_8 = 0;
    while( true ) {
      iVar1 = FUN_004d29a0();
      if (iVar1 <= local_8) break;
      puVar2 = (undefined4 *)FUN_004d2a00(local_8);
      (**(code **)*puVar2)();
      local_8 = local_8 + 1;
    }
    local_c = 0;
    while( true ) {
      iVar1 = FUN_004d2d60();
      if (iVar1 <= local_c) break;
      FUN_004d2dc0(local_c);
      FUN_0047a120();
      local_c = local_c + 1;
    }
  }
  *(undefined1 *)(param_1 + 0x183c) = 0;
  return;
}

