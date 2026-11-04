
undefined8 FUN_004fb260(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    uVar3 = 0xffffffff;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xe0);
    if (iVar1 == 0) {
      uVar2 = 0xffffffff;
      uVar3 = 0xffffffff;
    }
    else {
      uVar2 = *(undefined4 *)(iVar1 + 0x68);
      uVar3 = *(undefined4 *)(iVar1 + 0x6c);
    }
  }
  return CONCAT44(uVar3,uVar2);
}

