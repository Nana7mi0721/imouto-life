
void FUN_00678240(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  uVar2 = *(uint *)(param_2 + 8);
  puVar4 = *(undefined4 **)(param_1 + 0xbc);
  puVar1 = (undefined4 *)(param_2 + 0xc);
  uVar3 = 0x400;
  while( true ) {
    if (uVar2 < uVar3) {
      uVar3 = uVar2;
    }
    FUN_00677370(param_1,puVar1,uVar3);
    uVar2 = uVar2 - uVar3;
    if ((uVar2 == 0) || (puVar4 == (undefined4 *)0x0)) break;
    uVar3 = *(uint *)(param_1 + 0xc0);
    puVar1 = puVar4 + 1;
    puVar4 = (undefined4 *)*puVar4;
  }
  if (uVar2 != 0) {
    FUN_00668620(param_1,s_error_writing_ancillary_chunked_c_00a0d5ac);
  }
  return;
}

