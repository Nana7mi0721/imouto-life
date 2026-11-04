
undefined4 FUN_00586b00(void)

{
  int in_EAX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(int *)(in_EAX + 0x48c) != 0) {
    FUN_005421c0(in_EAX + 0x58);
  }
  if (*(int *)(in_EAX + 0x8cc) != 0) {
    FUN_005421c0(in_EAX + 0x498);
  }
  if (*(int *)(in_EAX + 0xd0c) != 0) {
    local_8 = *(undefined4 *)(in_EAX + 0x50);
    local_4 = *(undefined4 *)(in_EAX + 0x54);
    local_10 = 0;
    local_c = 0;
    FUN_00518620(&local_10,*(undefined4 *)(in_EAX + 0x40),*(undefined4 *)(in_EAX + 0x44),
                 *(undefined4 *)(in_EAX + 0x10),in_EAX + 0x8d8,0,0,0,0,0);
    if (*(int *)(in_EAX + 0xd0c) != 0) {
      FUN_005421c0(in_EAX + 0x8d8);
    }
  }
  return 0;
}

