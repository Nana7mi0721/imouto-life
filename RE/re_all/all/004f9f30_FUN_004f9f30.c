
void FUN_004f9f30(uint param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = __aullshr();
  param_3[3] = uVar1 & 0x1f;
  iVar2 = __aulldiv(uVar1 & 0x1e0,0,0x20,0);
  param_3[4] = iVar2 + -1;
  iVar2 = __aulldiv(uVar1 & 0xfe00,0,0x200,0);
  param_3[5] = iVar2 + 0x7bc;
  uVar3 = __aulldiv(param_1 & 0xf800,0,0x800,0);
  param_3[2] = uVar3;
  uVar3 = __aulldiv(param_1 & 0x7e0,0,0x20,0);
  param_3[1] = uVar3;
  uVar3 = __allmul(param_1 & 0x1f,0,2,0);
  *param_3 = uVar3;
  return;
}

