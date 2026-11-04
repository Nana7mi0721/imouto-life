
void FUN_00679300(int param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  uVar3 = *(int *)(param_1 + 0x118) + 1;
  *(uint *)(param_1 + 0x118) = uVar3;
  if (*(uint *)(param_1 + 0x108) <= uVar3) {
    if (*(char *)(param_1 + 0x154) != '\0') {
      *(undefined4 *)(param_1 + 0x118) = 0;
      if ((*(byte *)(param_1 + 0x7c) & 2) == 0) {
        bVar1 = *(char *)(param_1 + 0x155) + 1;
        *(byte *)(param_1 + 0x155) = bVar1;
        if (bVar1 < 7) {
          do {
            *(uint *)(param_1 + 0x10c) =
                 ((*(int *)(param_1 + 0x100) - (uint)(byte)(&DAT_0081f124)[bVar1]) + -1 +
                 (uint)(byte)(&DAT_0081f12c)[bVar1]) / (uint)(byte)(&DAT_0081f12c)[bVar1];
            uVar3 = ((*(int *)(param_1 + 0x104) - (uint)(byte)(&DAT_0081f134)[bVar1]) + -1 +
                    (uint)(byte)(&DAT_0081f13c)[bVar1]) / (uint)(byte)(&DAT_0081f13c)[bVar1];
            *(uint *)(param_1 + 0x108) = uVar3;
            if ((*(int *)(param_1 + 0x10c) != 0) && (uVar3 != 0)) break;
            bVar1 = bVar1 + 1;
            *(byte *)(param_1 + 0x155) = bVar1;
          } while (bVar1 < 7);
        }
      }
      else {
        *(char *)(param_1 + 0x155) = *(char *)(param_1 + 0x155) + '\x01';
      }
      if (*(byte *)(param_1 + 0x155) < 7) {
        if (*(undefined4 **)(param_1 + 0x120) == (undefined4 *)0x0) {
          return;
        }
        uVar3 = (uint)*(byte *)(param_1 + 0x15c) * (uint)*(byte *)(param_1 + 0x159);
        if (uVar3 < 8) {
          uVar3 = *(int *)(param_1 + 0x100) * uVar3 + 7 >> 3;
        }
        else {
          uVar3 = (uVar3 >> 3) * *(int *)(param_1 + 0x100);
        }
        puVar4 = *(undefined4 **)(param_1 + 0x120);
        for (uVar2 = uVar3 + 1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        for (uVar3 = uVar3 + 1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined1 *)puVar4 = 0;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
        return;
      }
    }
    FUN_00677850(param_1,0,0,4);
  }
  return;
}

