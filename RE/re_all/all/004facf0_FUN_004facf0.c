
undefined8 FUN_004facf0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar1 = 0;
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xe0);
    if (iVar2 == 0) {
      iVar1 = 0;
      iVar2 = 0;
    }
    else {
      iVar1 = *(uint *)(iVar2 + 0x40) + *(uint *)(iVar2 + 0xc0);
      iVar2 = *(int *)(iVar2 + 0x44) + *(int *)(iVar2 + 0xc4) +
              (uint)CARRY4(*(uint *)(iVar2 + 0x40),*(uint *)(iVar2 + 0xc0));
    }
  }
  return CONCAT44(iVar2,iVar1);
}

