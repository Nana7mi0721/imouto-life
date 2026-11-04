
undefined4 FUN_0059c120(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_0056d380(param_1,0,0x2777c);
  FUN_0056d380(param_1 + 0x2717c,0xff,0x600);
  puVar2 = (undefined4 *)(param_1 + 0x5448);
  iVar1 = 4;
  do {
    FUN_0056d380(puVar2 + -0x150d,0,0x408);
    puVar2[-0x140c] = 0x100;
    puVar2[-0x140b] = 0x10;
    FUN_0056d380(puVar2 + -0x101,0,0x408);
    *puVar2 = 0x10;
    puVar2[1] = 0x10;
    FUN_0056d380(puVar2 + 0x130b,0,0x408);
    puVar2[0x140c] = 0x10;
    puVar2[0x140d] = 4;
    FUN_0056d380(puVar2 + 0x2717,0,0x408);
    puVar2[0x2818] = 0xe0;
    puVar2[0x2819] = 0x10;
    FUN_0056d380(puVar2 + 0x3b23,0,0x408);
    puVar2[0x3c24] = 0x10;
    puVar2[0x3c25] = 0x10;
    FUN_0056d380(puVar2 + 0x4f2f,0,0x408);
    puVar2[0x5030] = 0x10;
    puVar2[0x5031] = 4;
    puVar2 = puVar2 + 0x503;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return 0;
}

