
undefined4 FUN_0055c780(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined2 local_14;
  undefined2 local_12;
  undefined4 local_10;
  undefined4 local_c;
  ushort local_8;
  undefined2 local_6;
  undefined2 local_4;
  
  FUN_0056d380(&local_14,0,0x12);
  local_4 = 0;
  local_14 = 1;
  local_12 = 1;
  local_10 = 0xac44;
  local_6 = 0x10;
  local_8 = 2;
  local_c = 0x15888;
  puVar2 = &DAT_00a83cb8;
  do {
    iVar1 = FUN_005514a0(puVar2,(uint)local_8 * 0x5622,&local_14,0,1,0,0);
    if (iVar1 != 0) {
      FUN_0056bb10(&DAT_007d6430);
      return 0xffffffff;
    }
    puVar2 = puVar2 + 0x77;
  } while ((int)puVar2 < 0xa8424c);
  return 0;
}

