
void FUN_005bfae0(void)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  uint *puVar4;
  
  if (DAT_00f3a070 != 0) {
    puVar4 = &DAT_00a380f8;
    piVar3 = (int *)(*(int *)(DAT_00ef1b94 + 8) + 8);
    do {
      if ((((DAT_00cc79c0 == 0) || (uVar1 = *puVar4, (int)uVar1 < 0)) ||
          ((uVar1 & 0x7c000000) != DAT_00cc79e8)) ||
         (((DAT_00cc79f0 <= (int)(uVar1 & 0xffff) ||
           (piVar2 = *(int **)(DAT_00cc79c4 + (uVar1 & 0xffff) * 4), piVar2 == (int *)0x0)) ||
          ((*piVar2 * 0x10000 != (uVar1 & 0x3ff0000) || (piVar2[4] != 0)))))) {
        FUN_0056d420(piVar3 + -2,&DAT_00860970,0x40);
      }
      else {
        piVar3[-2] = piVar2[0x6b];
        piVar3[-1] = piVar2[0x6f];
        *piVar3 = piVar2[0x73];
        piVar3[1] = piVar2[0x77];
        piVar3[2] = piVar2[0x6c];
        piVar3[3] = piVar2[0x70];
        piVar3[4] = piVar2[0x74];
        piVar3[5] = piVar2[0x78];
        piVar3[6] = piVar2[0x6d];
        piVar3[7] = piVar2[0x71];
        piVar3[8] = piVar2[0x75];
        piVar3[9] = piVar2[0x79];
        piVar3[10] = piVar2[0x6e];
        piVar3[0xb] = piVar2[0x72];
        piVar3[0xc] = piVar2[0x76];
        piVar3[0xd] = piVar2[0x7a];
      }
      puVar4 = puVar4 + 1;
      piVar3 = piVar3 + 0x10;
    } while ((int)puVar4 < 0xa38104);
    *(undefined4 *)(DAT_00ef1b94 + 0xc) = 1;
  }
  return;
}

