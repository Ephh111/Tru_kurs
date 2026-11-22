#pragma once

/**
 * @file calc.h
 * @brief Заголовочный файл вычислений.
 */

#include <vector>
#include <cstdint>

/**
 * @brief Класс для выполнения вычислений над векторами.
 */
class Calc {
public:
    /**
     * @brief Вычисляет среднее арифметическое элементов вектора.
     * @details В случае переполнения типа int16_t результат ограничивается
     * максимальным (32767) или минимальным (-32768) значением.
     * @param vec Константная ссылка на вектор 16-битных целых чисел.
     * @return Среднее значение в виде int16_t.
     */
    static int16_t compute_average(const std::vector<int16_t>& vec);
};
