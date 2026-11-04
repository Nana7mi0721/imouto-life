
undefined4 FUN_0057e140(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (DAT_00aa4fa0 == 0) {
    return 0xffffffff;
  }
  if (param_1 != (undefined4 *)0x0) {
    if (DAT_00aa4254 == 0) {
      puVar1 = (undefined4 *)(&DAT_00aa4274 + param_2 * 0x34);
    }
    else {
      puVar1 = (undefined4 *)(&DAT_00aa488c + param_2 * 0x38);
    }
    *param_1 = *puVar1;
    param_1[1] = puVar1[1];
    *(undefined1 *)(param_1 + 2) = *(undefined1 *)(puVar1 + 2);
    *(undefined *)((int)param_1 + 9) = *(undefined *)((int)puVar1 + 9);
    *(undefined *)((int)param_1 + 10) = *(undefined *)((int)puVar1 + 10);
    *(undefined *)((int)param_1 + 0xb) = *(undefined *)((int)puVar1 + 0xb);
    *(undefined1 *)(param_1 + 3) = *(undefined1 *)(puVar1 + 3);
    *(undefined *)((int)param_1 + 0xd) = *(undefined *)((int)puVar1 + 0xd);
    *(undefined *)((int)param_1 + 0xe) = *(undefined *)((int)puVar1 + 0xe);
    *(undefined *)((int)param_1 + 0xf) = *(undefined *)((int)puVar1 + 0xf);
    *(undefined1 *)(param_1 + 4) = *(undefined1 *)(puVar1 + 4);
    *(undefined *)((int)param_1 + 0x11) = *(undefined *)((int)puVar1 + 0x11);
    *(undefined *)((int)param_1 + 0x12) = *(undefined *)((int)puVar1 + 0x12);
    *(undefined *)((int)param_1 + 0x13) = *(undefined *)((int)puVar1 + 0x13);
    param_1[5] = puVar1[5];
    param_1[6] = puVar1[6];
    param_1[7] = puVar1[7];
    param_1[8] = puVar1[8];
    param_1[9] = puVar1[9];
    param_1[10] = puVar1[10];
    param_1[0xb] = puVar1[0xb];
    param_1[0xc] = puVar1[0xc];
  }
  return 0;
}

