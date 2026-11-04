
void FUN_005e86d0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined1 *param_4,
                 undefined1 *param_5,undefined4 *param_6,undefined4 *param_7,undefined4 *param_8,
                 undefined4 *param_9,char *param_10,undefined4 *param_11,char *param_12,
                 undefined4 *param_13)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char *pcVar3;
  
  uVar1 = 0;
  puVar2 = (undefined4 *)*param_1;
  *puVar2 = *param_2;
  puVar2[1] = param_2[1];
  puVar2[2] = param_2[2];
  puVar2[3] = *param_3;
  puVar2[4] = param_3[1];
  puVar2[5] = param_3[2];
  *(undefined1 *)((int)puVar2 + 0x1a) = *param_4;
  *(undefined1 *)((int)puVar2 + 0x19) = param_4[1];
  *(undefined1 *)(puVar2 + 6) = param_4[2];
  *(undefined1 *)((int)puVar2 + 0x1b) = param_4[3];
  *(undefined1 *)((int)puVar2 + 0x1e) = *param_5;
  *(undefined1 *)((int)puVar2 + 0x1d) = param_5[1];
  *(undefined1 *)(puVar2 + 7) = param_5[2];
  *(undefined1 *)((int)puVar2 + 0x1f) = param_5[3];
  if (param_6 == (undefined4 *)0x0) {
    puVar2[8] = 0;
    puVar2[9] = 0;
  }
  else {
    puVar2[8] = *param_6;
    puVar2[9] = param_6[1];
  }
  puVar2[10] = 0x3f800000;
  puVar2[0xb] = 0x3f800000;
  if (param_7 == (undefined4 *)0x0) {
    puVar2[0xc] = 0;
  }
  else {
    puVar2[0xc] = *param_7;
    uVar1 = param_7[1];
  }
  puVar2[0xd] = uVar1;
  pcVar3 = (char *)(puVar2 + 0x10);
  puVar2[0xe] = 0x3f800000;
  puVar2[0xf] = 0x3f800000;
  if (param_8 != (undefined4 *)0x0) {
    *(undefined4 *)pcVar3 = *param_8;
    puVar2[0x11] = param_8[1];
    puVar2[0x12] = param_8[2];
    pcVar3 = (char *)(puVar2 + 0x13);
  }
  if (param_9 != (undefined4 *)0x0) {
    *(undefined4 *)pcVar3 = *param_9;
    *(undefined4 *)(pcVar3 + 4) = param_9[1];
    *(undefined4 *)(pcVar3 + 8) = param_9[2];
    pcVar3 = pcVar3 + 0xc;
  }
  if (param_10 != (char *)0x0) {
    *pcVar3 = *param_10 * '\x03';
    pcVar3[1] = param_10[1] * '\x03';
    pcVar3[2] = param_10[2] * '\x03';
    pcVar3[3] = param_10[3] * '\x03';
    pcVar3 = pcVar3 + 4;
  }
  if (param_11 != (undefined4 *)0x0) {
    *(undefined4 *)pcVar3 = *param_11;
    *(undefined4 *)(pcVar3 + 4) = param_11[1];
    *(undefined4 *)(pcVar3 + 8) = param_11[2];
    *(undefined4 *)(pcVar3 + 0xc) = param_11[3];
    pcVar3 = pcVar3 + 0x10;
  }
  if (param_12 != (char *)0x0) {
    *pcVar3 = *param_12 * '\x03';
    pcVar3[1] = param_12[1] * '\x03';
    pcVar3[2] = param_12[2] * '\x03';
    pcVar3[3] = param_12[3] * '\x03';
    pcVar3 = pcVar3 + 4;
  }
  if (param_13 != (undefined4 *)0x0) {
    *(undefined4 *)pcVar3 = *param_13;
    *(undefined4 *)(pcVar3 + 4) = param_13[1];
    *(undefined4 *)(pcVar3 + 8) = param_13[2];
    *(undefined4 *)(pcVar3 + 0xc) = param_13[3];
    pcVar3 = pcVar3 + 0x10;
  }
  *param_1 = pcVar3;
  return;
}

