# Задание 2

## Статья
Название: An Ethical Trajectory Planning Algorithm for Autonomous Vehicles

Для цитирования: Maximilian Geisslinger, Franziska Poszler, Markus Lienkamp. An Ethical Trajectory Planning Algorithm for Autonomous Vehicles //arXiv preprint arXiv:2212.08577. - 2022

URL: https://arxiv.org/abs/2212.08577

## Характеристика используемых данных
### Методы проведения эксперимента

Эксперимент проводился с использованием компьютерного моделирования, который позволил сравнить разработанный алгоритм с результатами работы других алгоритмов. Результаты эксперимента были наглядно представлены в виде графиков, что обеспечило более полное понимание процесса исследования.
Для анализа эффективности различных подходов к планированию траектории автономных транспортных средств, авторы запустили три типа алгоритмов в 2000 сценариях моделирования. Они уделили особое внимание 100 наиболее значимым сценариям, которые были выбраны с целью максимальной релевантности анализу рисков. Такой подход позволил более детально рассмотреть последствия различных подходов к планированию и выявить возможные несчастные случаи.

### Описание используемых данных и их характеристики

В исследовании использовались данные о движении автономных транспортных средств (АТС) в различных сценариях дорожного движения предоставляемые CommonRoad. Эти сценарии включают в себя информацию о скорости, ускорении, расстоянии до других объектов на дороге и других параметрах движения. Для формирования сценариев использовались различные подходы: часть из них была записана в реальных дорожных условиях, в то время как другие создавались вручную с целью создания экстремальных ситуаций, наиболее репрезентативных для анализа безопасности. Эти сценарии охватывают разнообразные условия движения и были смоделированы в различных регионах мира. Такой подход позволяет учесть разнообразие дорожных ситуаций и обеспечить более всесторонний анализ предложенных алгоритмов. В статье отсутствует подробное описание вручную создаваемых экстремальных сценариев, поскольку это лишь общее описание данных, предоставляемых CommonRoad.

>"The scenarios are partly real-world recorded or handcrafted to create explicitly safety-critical situations. They cover a wide variety of environments, such as urban, rural, and highway, in different regions, such as the USA, Europe, and China."

### Способы обработки результатов эксперимента

Был проведён сравнительный анализ трех алгоритмов планирования траектории движения АТС, включая алгоритм разработанный авторами, на сценариях описанных выше. Авторы сравнивают три группы участников дорожного движения: сам беспилотный автомобиль, все остальные участники дорожного движения, кроме АТС, и уязвимые участники дорожного движения.

Сравнение с другими алгоритмами проводилось на основании следующих показателей:
1. Риски, возникающие в результате различных подходов к планированию.
   
   Уровень риска - это произведение вероятности столкновения $p$ и предполагаемого вреда от этого столкновения $H$.    
   Вероятность столкновения $p$ вычисляется с помощью нейросетевой модели, а оценка предполагаемого вреда $H$ основывается на массе, скорости, учитывая различие между защищенными и незащищенными участниками дорожного движения.    
   Формула расчета $H$:  
   $$H = {1 \over 1 + e^{c_{0} - c_{1}Δv - c_{area}}} (1)$$
   $$Δv_{A} = {m_{B} \over m_{A} + m_{B}} \sqrt {v^2_{A} + v^2_{B} - 2v_{A}v_{B}\cos\alpha} (2)$$
   , где $m$ и $v$ – масса и скорость двух участников дорожного движения $A$ и $B$, $α$ – угол столкновения, а $c_{0}$, $c_{1}$ и $c_{area}$ – эмпирически определенные коэффициенты (значения которых в статье не раскрываются).    
   Чтобы назначать значение риска для каждого участника дорожного движения в зависимости от планируемой траектории движения АТС используется формула:
   $$R(u) = max(p(u)H(u)) (3)$$
   > “In our work, we adopt the definition of risk as an expected value. Accordingly, risk is defined as the product of a probability that a certain event will occur and a measure of the consequences of that event”

2. Ущерб в смоделированных несчастных случаях.
   
   Ущерб рассчитывается на основании массы и скорости столкнувшихся объектов, а также угла и площади удара по формуле (1) выше.  
  
   Ущербы во всех смоделированных несчастных случаях суммируются и получается  суммарный ущерб для соответствующих групп участников дорожного движения, по которому и производится дальнейшее сравнение алгоритмов.  
  
   > “Other impact factors that we consider are the mass of both colliding parties, the angle of impact, and the impact area.”


Новый алгоритм продемонстрировал хорошие результаты как по показателю риска, так и по показателю суммарного ущерба.

### Правомерность выводов по итогам исследования

Проведенный анализ показывает, что учет рисков при планировании траектории способствует снижению общего риска для всех участников дорожного движения. Сравнивая эгоистический алгоритм с предложенным нами этическим подходом, мы наблюдаем те же риски для АТС, что и при использовании эгоистического алгоритма. Однако, в то же время, риски для сторонних участников дорожного движения, и особенно для уязвимых, значительно ниже. Оценка ущерба в смоделированных несчастных случаях  показывает, что расчетный вред для этических и эгоистичных алгоритмов аналогичен.

Эксперимент проводится с использованием сценариев, охватывающих большое количество как реальных дорожных условий, так и созданных вручную экстремальных ситуаций, что позволяет рассмотреть большинство возможных исходов. Статистические данные относительно других алгоритмов занимают выигрышную позицию, из чего можно сделать вывод, что эксперимент является всеобъемлющим и подтверждает правомерность заключения о том, что он является эффективным для справедливого распределения рисков между участниками дорожного движения. Из этого следует, что приведенный авторами алгоритм будет полезен в области беспилотных транспортных средств, робототехники и других направлениях.

## Характеристика выводов
### Соответствие результата статьи
#### Сравнение достигнутых результатов с поставленными целями и задачами и степень раскрытия результатов

Итогом работы авторов стал разработанный этический алгоритм для планирования траектории АТС. Справедливость распределения риска была подтверждена эмпирически в разделе “Результаты (ориг. Results)” - этический алгоритм способствует снижению общего риска для всех участников дорожного движения при планировании траектории в сравнении с эгоистичным и стандартным. Таким образом, поставленная цель была достигнута.  

Результат поставленной цели в статье раскрыт подробно в разделе “Обсуждение (ориг. Discussion )”. Авторы пришли к выводу, что они обеспечивают основу для этического планирования траектории с помощью разработанного алгоритма, который позволяет правильно представить сложную среду беспилотных транспортных средств. Принятые ими этические принципы обеспечивают прозрачность принятия решений и будущем они также могут представлять интерес для других приложений ИИ.  

Авторы статьи поставили перед собой ряд задач:  
  1. Генерация всех траекторий движения АТС с этически нейтральными расчетами значений риска и присвоением их для каждой траектории.
     
     В разделе “Расчеты Риска (ориг. Risk Calculation)” авторы сгенерировали все траектории движения АТС с помощью нейросетевой модели. Для каждой траектории авторы расчитали этически-нейтральные значения риска по выведенным математическим формулам. Таким образом, первая задача была выполнена.
     
     Результат поставленной задачи в статье не раскрыт. Приведено только описание решения задачи, а выводы по проведенному решению отсутствуют.

  2. Выбор набора траекторий, обеспечивающих минимальный возможный риск.
     
     В разделе “Максимально Допустимый Риск (ориг. Maximum Acceptable Risk)” авторы ввели понятие максимально допустимого риска, который определяет, какая траектория разрешена, а какая - только при отсутствии других вариантов. Согласно этой концепции, авторы классифицируют траектории на четыре уровня валидности. Выбор наиболее благоприятной траектории осуществляется с самого высокого уровня валидности. Таким образом, вторая задача была выполнена.
     
     Результат поставленной задачи раскрыт в статье. Авторы делают вывод, что работа с максимально допустимым риском создает, с одной стороны, более эффективные решения при условии надежной оценки риска АТС и, с другой стороны, прозрачность по отношению ко всем участникам дорожного движения, обеспечивающим функционирование АТС.

  3. Расчет показателей суммарных траекторных издержек для выбранных допустимых траекторий с использованием основных этических принципов.
     
     В разделе “Распределение рисков (ориг. Risk Distribution)” авторы рассчитали суммарные издержки для траекторий, находящихся в пределах наивысшего доступного уровня валидности. Были выделены критерии, влияющие на оценку маршрута: мобильность, безопасность и комфорт. Для расчета стоимости безопасности была использована взвешенная сумма четырех этических принципов: Байесовский, Равенства и Максимина, описанных в разделе “Принцип Байеса, Равенства и Максимина (ориг. Bayes, Equality & Maximin Principle)”, а также Принцип Ответственности из одноименного раздела (ориг. Responsibility Principle). Таким образом, третья задача была выполнена.
     
     Результат поставленной задачи раскрыт в статье. Подробно описан каждый из принципов и его этическое влияние на расчет суммарных издержек.

  4. Проведение сравнительного анализа распределения рисков между разработанным этическим алгоритмом и другими существующими методами планирования траектории.
     
     В разделе “Результаты (ориг. Results)” авторы провели сравнительный анализ этического алгоритма с эгоистичным и стандартным алгоритмами в 2000 симуляционных сценариях. Были проанализированы риски, возникающие в результате различных подходов к планированию, а также смоделированные несчастные случаи и связанный с ними ущерб. Для наглядности анализа были приведены соответствующие графики - График Риска и График Суммарного Ущерба. Результаты показали, что разработанный алгоритм эффективнее и справедливее по сравнению с другими. Таким образом, четвертая задача была выполнена.
     
     Результат поставленной задачи раскрыт в статье. Приведено распределение рисков и ущерба между участниками дорожного движени, на основании которых сделан вывод, что разработанное справедливое распределение рисков перекладывает риски с уязвимых участников дорожного движения на автономное транспортное средство, предоставляя уязвимым участникам дорожного движения такой же уровень защиты, как и другим участникам дорожного движения.  

Подводя итог, авторы достигли ожидаемых результатов.  


#### Направления для дальнейших исследований

1. Авторы предлагают для дальнейшего исследование определение наиболее оптимальных весовых коэффициентов алгоритма, поскольку разные страны, культуры или даже отдельные люди могут требовать разных этических акцентов.
>”While we provide a framework for ethical trajectory planning with our algorithm, we do not yet specify parameters such as the weighting factors of each principle or a value for the maximum acceptable risk….The definition of these parameters should be the result of a social consensus agreed upon by all road users and susceptible to future research.”

2. Также авторы акцентируют внимание на том, что они оставляют в своем алгоритме возможность для модификаций, которые могут потребоваться в зависимости от различных культур или областей применения, но предлагают задуматься о возможном влиянии этических норм на предвзятость моделирования на принятие этических решений.
>”For further development, it is important to account for possible bias in the modeling, which automatically influences ethical decision-making in our approach”
>”However, to what extent such a cultural determination is admissible would be subject to further research”

3. В алгоритме авторы оставляют возможность для принятия маневра, повышающего риски, но выполнимого в случае невозможности выполнения более безопасных траекторий. Они оставляют возможность для исследования и определения порога риска при котором маневр является допустимым при наличии более безопасной траектории.
>”It enables social debate on an important question within our society: “How much risk are we as a society willing to accept in exchange for mobility?” This question goes far beyond the issue of autonomous vehicles. It is likely to arise in more and more areas where understanding of risk through modern algorithms and big data is growing”

### Достигнутый результат
#### Чем является результат

Результат исследования представляет собой этический алгоритм планирования траектории для автономных транспортных средств в соответствии с нормативными указаниями и рекомендациями по предотвращению аварий.

Факторы обеспечивающие этичность алгоритма:
  1. Рассмотрение ущерба без учета:
     * Суждения о том, какой физический вред более серьезный.
     * Материального ущерба.
     * Личностных характеристик, таких как возраст, пол или показатели качества жизни.
  2. Учет степени защищенности участников дорожного движения - защищенные (автомобили, грузовики и т.д.), незащищенные (пешеходы, велосипедисты и т.д.)
  3. Использование различных стоимостных функций в зависимости от наивысшего доступного уровня валидности траектории.
  4. Перевод принципов этического распределения в математическое представление в виде суммарных траекторных издержек, объединяя такие принципы, как принцип Байеса, равенства, максимина и ответственности.
     * Использование принципа Байеса для минимизации общего риска.
     * Использование принципа равенства для равномерного распределения рисков между участниками дорожного движения, чтобы использование принципа Байеса не создавало смещения с исключительно высокими рисками для отдельных участников дорожного движения в пользу низкого общего риска.
     * Использование принципа максимина для  раздельного рассмотрения вероятности столкновения и вреда.
     * Использование моральной ответственности для учета справедливости и гарантии, что участники дорожного движения ведут себя ответственно. 


Нормативные указания формируют:
  1. Комиссия ЕС «Горизонт» - Ethics of Connected and Automated Vehicles: recommendations on road safety, privacy, fairness, explainability and responsibility.
  2. Немецкий этический кодекс - The German Ethics Code for Automated and Connected Driving.
  3. Экономическая комиссия Организации Объединенных Наций для Европы (ЕЭК ООН) - World Forum for Harmonization of Vehicle Regulations. Framework document on automated/autonomous vehicles.
  4. Этические комитеты - AI4people: Ethical guidelines for the automotive sector-fundamental requirements and practical recommendations.
Пороговые значения риска неявно устанавливаются властями и государственными нормативными актами: ограничение скорости в районах или правила безопасного расстояния неявно представляют собой взвешивание приемлемого риска по сравнению с такими значениями, как транспортный поток для всех участников дорожного движения.

#### Характер результата

Результат исследования носит прикладной характер, так как конечным продуктом исследования является алгоритм, готовый к использованию автономными транспортными средствами для повышения безопасности на дороге.

#### Характеристики достигнутого резутата

На рисунке 5 с помощью графика вида «ящик с усами» отображены риски в у.е. для каждой из трех групп участников дорожного движения ((1) сам беспилотный автомобиль (АТС), (2) все остальные участники дорожного движения, кроме АТС, и (3) уязвимые участники дорожного движения) с использованием трех типов алгоритмов - этический, эгоистический и стандартный. Данные графики, позволяют очень компактно и наглядно представлять порядковые статистики одномерного закона распределения: квартили, медиану, наблюдаемые минимальное и максимальное значение выборки, а также отображать выбросы.

На основе данных, отображенных на рисунке 5 - представленный этический алгоритм в сравнении с эгоистичным алгоритмом имеет одинаковый уровень риска для АТС около 0.015 у.е., в то время как у стандартного значение около 0.025 у.е. Риски для сторонних участников дорожного движения, в особенности для уязвимых, значительно ниже - около 0.055 у.е. для этического алгоритма, в сравнении с 0.07 у.е. для эгоистического и 0.125 у.е. для стандартного. Таким образом, использование этического алгоритма переносит риск с уязвимых транспортных средств на АТС в приемлемом для АТС масштабе.


На рисунке 6  с помощью столбчатой диаграммы отображены суммарные ущербы в у.е. для  каждой из трех групп участников дорожного движения в смоделированных несчастных случаях ((1) сам беспилотный автомобиль (АТС), (2) все остальные участники дорожного движения, кроме АТС, и (3) уязвимые участники дорожного движения) с использованием трех типов алгоритмов - этический, эгоистический и стандартный.


На основе данных, отображенных на рисунке 6 - рассчитанный ущерб для этического и эгоистичного алгоритмов аналогичны.  Для АТС около 9 у.е. для этического и эгоистического алгоритма и 24 у.е. для стандартного. Для сторонних участников дорожного движения около 6.5 у.е. для этического и эгоистического алгоритма и 11 у.е. для стандартного. Для уязвимых около 2 у.е. для этического и около 3 у.е для эгоистического алгоритма, в то время как у стандартного значение около 6 у.е. В несчастных случаях этический алгоритм обеспечивает такой же уровень безопасности, как и эгоистический алгоритм, однако он выдает более благоприятные результаты для уязвимых групп.

Рисунок 5 - Распределение рисков по 100 наиболее вероятным рискам.

Рисунок 6 - Совокупный личный ущерб, причиненный в результате несчастных случаев в течение 2000 смоделированных сценариев.

#### Границы применимости и степень универсальности

Исследование охватывает широкий спектр условий в разных регионах - городские, сельские и автомобильные дороги в США, Европе и Китае, поэтому границы применимости результата зависят только от конкретных условий дорожного движения и требований к безопасности и этике. Возможность модификации и настройки весовых коэффициентов алгоритма обеспечивает его универсальность.

#### Технические ограничения

Технические ограничения включают вычислительную сложность алгоритма, необходимость точной калибровки датчиков и ограниченность информации, которую можно передать алгоритму.
>”For ethical decisionmaking, however, we must acknowledge the limited information that can reasonably be provided to the algorithm from a technical point of view”

#### Недостатки решения

Недостатком решения может быть его сложность в реализации и необходимость дополнительной адаптации для различных сценариев дорожного движения, алгоритм не охватывает всех этических аспектов. 
> “However, a particular parameter set may not apply universally. Different countries, cultures, or even individuals may demand different ethical emphases. ”
> ”As Kauppinen correctly notes, the determination of moral responsibility is arbitrarily complex. There is a difference between a pedestrian running into the street out of carelessness and someone being pursued and running for his life.”

#### Вопросы касательно результата для дальнейшего исследования:

Авторам стоит рассмотреть следующие вопросы для дальнейших исследований:
1. Расширение применимости алгоритма на различные типы транспортных средств и дорожные условия.
2. Адаптация алгоритма для учета человеческого поведения на дороге в критических ситуациях.
3. Оценка влияния алгоритма на безопасность и эффективность дорожного движения в реальных условиях, а не в симуляции.