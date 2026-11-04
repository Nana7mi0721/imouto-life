
undefined4 FUN_00561be0(void)

{
  int *piVar1;
  uint in_EAX;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  code *local_8;
  undefined4 local_4;
  
  iVar2 = FUN_0057e0e0();
  if (((((iVar2 != 0) && (DAT_00cc4db0 != 0)) && (-1 < (int)in_EAX)) &&
      (((in_EAX & 0x7c000000) == DAT_00cc4dd8 && ((int)(in_EAX & 0xffff) < DAT_00cc4de0)))) &&
     ((piVar1 = *(int **)(DAT_00cc4db4 + (in_EAX & 0xffff) * 4), piVar1 != (int *)0x0 &&
      ((*piVar1 * 0x10000 == (in_EAX & 0x3ff0000) && (piVar1[4] == 0)))))) {
    if (piVar1[0x482] == 1) {
      return 0;
    }
    iVar2 = FUN_0055b9b0(&local_28,&local_24,piVar1 + 0x47d,0x12,piVar1[0x93f],piVar1[0x93e]);
    if (-1 < iVar2) {
      uVar3 = FUN_005610d0(0);
      uVar4 = FUN_0055f530();
      uVar5 = FUN_005611b0();
      local_20 = FUN_00561000();
      FUN_0055f370();
      FUN_00580b80();
      local_4 = FUN_0052d000(local_28,local_24);
      puVar6 = (undefined4 *)FUN_0052c7a0();
      local_1c = *puVar6;
      local_18 = puVar6[1];
      local_14 = puVar6[2];
      local_10 = puVar6[3];
      local_c = puVar6[4];
      local_8 = (code *)puVar6[5];
      uVar7 = FUN_005809a0(3,0);
      iVar2 = FUN_00560330(&local_1c,0,uVar7,0,&local_24,0xffffffff);
      if (iVar2 == -1) {
        FUN_0056bb10(&DAT_007d67cc);
        return 0xffffffff;
      }
      (*local_8)(local_4);
      FUN_0056e1d0(local_28);
      FUN_0055cde0(uVar3,uVar7);
      FUN_0055d200(uVar4,uVar7);
      FUN_0055d100(uVar5,uVar7);
      FUN_0055f460(local_20,uVar7);
      return 0;
    }
  }
  return 0xffffffff;
}

