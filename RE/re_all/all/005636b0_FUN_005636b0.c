
undefined4 * FUN_005636b0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puStack_14;
  int *piStack_10;
  undefined1 *puStack_c;
  int *local_8;
  undefined1 local_4 [4];
  
  puStack_c = local_4;
  local_8 = (int *)0x0;
  piStack_10 = (int *)&DAT_0085efa4;
  puStack_14 = DAT_00aae0bc;
  iVar1 = (**(code **)*DAT_00aae0bc)();
  if (-1 < iVar1) {
    piVar2 = local_8;
    (**(code **)(*piStack_10 + 0x18))(piStack_10,local_8,&puStack_14);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return puStack_14;
}

