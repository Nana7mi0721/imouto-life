
uint FUN_0067c580(uint param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  param_1 = ~param_1;
  for (; (param_3 != 0 && (((uint)param_2 & 3) != 0)); param_2 = (uint *)((int)param_2 + 1)) {
    param_1 = param_1 >> 8 ^ *(uint *)(&DAT_0081f9fc + (param_1 & 0xff ^ (uint)(byte)*param_2) * 4);
    param_3 = param_3 - 1;
  }
  if (0x1f < param_3) {
    uVar2 = param_3 >> 5;
    puVar3 = param_2;
    do {
      param_1 = param_1 ^ *puVar3;
      uVar1 = *(uint *)(&DAT_0081fdfc + (param_1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_008201fc + (param_1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0081f9fc + (param_1 >> 0x18) * 4) ^
              *(uint *)(&DAT_008205fc + (param_1 & 0xff) * 4) ^ puVar3[1];
      uVar1 = *(uint *)(&DAT_0081fdfc + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_008201fc + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0081f9fc + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_008205fc + (uVar1 & 0xff) * 4) ^ puVar3[2];
      uVar1 = *(uint *)(&DAT_0081fdfc + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_008201fc + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0081f9fc + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_008205fc + (uVar1 & 0xff) * 4) ^ puVar3[3];
      uVar1 = *(uint *)(&DAT_0081fdfc + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_008201fc + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0081f9fc + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_008205fc + (uVar1 & 0xff) * 4) ^ puVar3[4];
      uVar1 = *(uint *)(&DAT_0081fdfc + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_008201fc + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0081f9fc + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_008205fc + (uVar1 & 0xff) * 4) ^ puVar3[5];
      uVar1 = *(uint *)(&DAT_0081fdfc + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_008201fc + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0081f9fc + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_008205fc + (uVar1 & 0xff) * 4) ^ puVar3[6];
      param_2 = puVar3 + 8;
      param_3 = param_3 - 0x20;
      uVar1 = *(uint *)(&DAT_0081fdfc + (uVar1 >> 0x10 & 0xff) * 4) ^
              *(uint *)(&DAT_008201fc + (uVar1 >> 8 & 0xff) * 4) ^
              *(uint *)(&DAT_0081f9fc + (uVar1 >> 0x18) * 4) ^
              *(uint *)(&DAT_008205fc + (uVar1 & 0xff) * 4) ^ puVar3[7];
      param_1 = *(uint *)(&DAT_0081fdfc + (uVar1 >> 0x10 & 0xff) * 4) ^
                *(uint *)(&DAT_008201fc + (uVar1 >> 8 & 0xff) * 4) ^
                *(uint *)(&DAT_0081f9fc + (uVar1 >> 0x18) * 4) ^
                *(uint *)(&DAT_008205fc + (uVar1 & 0xff) * 4);
      uVar2 = uVar2 - 1;
      puVar3 = param_2;
    } while (uVar2 != 0);
  }
  if (3 < param_3) {
    uVar2 = param_3 >> 2;
    do {
      param_1 = param_1 ^ *param_2;
      param_2 = param_2 + 1;
      param_3 = param_3 - 4;
      param_1 = *(uint *)(&DAT_0081fdfc + (param_1 >> 0x10 & 0xff) * 4) ^
                *(uint *)(&DAT_008201fc + (param_1 >> 8 & 0xff) * 4) ^
                *(uint *)(&DAT_0081f9fc + (param_1 >> 0x18) * 4) ^
                *(uint *)(&DAT_008205fc + (param_1 & 0xff) * 4);
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  for (; param_3 != 0; param_3 = param_3 - 1) {
    param_1 = param_1 >> 8 ^ *(uint *)(&DAT_0081f9fc + (param_1 & 0xff ^ (uint)(byte)*param_2) * 4);
    param_2 = (uint *)((int)param_2 + 1);
  }
  return ~param_1;
}

